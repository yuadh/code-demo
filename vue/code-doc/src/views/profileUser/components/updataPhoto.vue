<template>
  <div class="photo-container">
      <img :src="img" class="img" ref="img">
      <div class="toolBar">
          <div class="cancel">取消</div>
          <div class="confirm" @click="toConfirm">完成</div>
      </div>
  </div>
</template>

<script>
import 'cropperjs/dist/cropper.css'
import Cropper from 'cropperjs'
import {changeUserPhotoAPI} from '@/api/index'
export default {
    name:'updataPhoto',
    props:{
        img:{
            type:[String,Object],
            required:true
        }
    },
    data(){
        return{
            cropper:null
        }
    },
    mounted(){
        const image = this.$refs.img
        this.cropper = new Cropper(image, {
                viewMode: 1,//限制裁剪框不超过画布的大小。
                dragMode: 'move',//裁剪的方式为移动裁剪
                aspectRatio: 1,//定义裁剪框的固定纵横比。
                cropBoxMovable: false,//不允许拖动裁剪框
                cropBoxResizable: false,//不允许修改裁剪框的大小
                background: false //不需要背景
        });
    },
    methods:{
        toConfirm(){
            // 此函数将获取裁剪的画布然后以blob形式进行处理
            this.cropper.getCroppedCanvas().toBlob(blob => {
                console.log(URL.createObjectURL(blob))
                this.updateUserPhoto(blob)
            })
        },
        async updateUserPhoto(blob){
             this.$toast.loading({
                message: '保存中...',
                forbidClick: true, // 禁止背景点击
                duration: 0 // 持续展示
            })
           try{
                const formData = new FormData() //因为后端接口的数据格式要求
                formData.append('photo',blob)
                const {data} = await changeUserPhotoAPI(formData) 
                console.log(data)
                // 关闭弹出层
                this.$emit('close')

                // 更新视图
                this.$emit('updataPhoto', data.data.photo)
                this.$toast.success('更新成功')
           }catch(error){
               this.$toast.fail('更新失败')
               console.log(error)
           }
        }
    }

}
</script>

<style lang="less" scoped>
    .photo-container{
        background-color: black;
        height: 100%;
        .img{
            max-width: 100%;
            display: block;
        }
        .toolBar{
            position: fixed;
            left: 0;
            right: 0;
            bottom: 0;
            display: flex;
            justify-content: space-between;
            .cancel,.confirm{
                width: 90px;
                height: 90px;
                font-size: 30px;
                display: flex;
                justify-content: center;
                color: #fff;
            }
        }
    }
</style>