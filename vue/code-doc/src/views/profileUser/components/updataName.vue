<template>
  <div class="updataName">
    <van-nav-bar
     title="设置昵称"
     left-text="取消"
     right-text="完成"
     @click-left="$emit('close')"
     @click-right="toConfirm"/>
    <div class="field-warp">
        <van-field
        v-model.trim="localName"
        rows="2"
        autosize
        type="textarea"
        maxlength="7"
        show-word-limit
        />
    </div>
  </div>
</template>

<script>
import {changeUserProfileAPI} from '@/api/index'
export default {
    name:'updataName',
    props:{
        value:{
            type:String,
            required:true
        }
    },
    data(){
        return{
            localName : this.value
        }
    },
    methods: {
        async toConfirm(){
            this.$toast.loading({
                message: '保存中...',
                forbidClick: true, // 禁止背景点击
                duration: 0 // 持续展示
            })
            try{
                const changeName = this.localName
                if(!changeName.length){
                    this.$toast('昵称不能为空')
                    return
                }
                // 
                await changeUserProfileAPI({
                    name:changeName
                })
                // 更新视图
                this.$emit('input', this.localName)

                // 关闭弹层
                this.$emit('close')
                // 提示成功
                this.$toast.success('更新成功')

            }catch(error){
                console.log(error)
                this.$toast.fail('更新失败')
            }
        }
    }
}
</script>

<style scoped lang="less">
    .field-warp{
        padding: 20px;
    }
</style>