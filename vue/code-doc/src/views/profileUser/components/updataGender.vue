<template>
  <div class="updataGender">
      <van-picker
       title="性别"
       show-toolbar
       :columns="columns"
       :default-index="value"
       @confirm="onConfirm"
       @cancel="$emit('close')"
       @change="onChange"
       />
  </div>
</template>

<script>
import {changeUserProfileAPI} from '@/api/index'
export default {
    name:'updataGender',
    props:{
        value :{
            type:Number,
            required:true
        }
    },
    data() {
        return {
            columns: ['男','女'],
            localGender:this.value
        };
    },
    methods: {
        async onConfirm() {
            this.$toast.loading({
                message:'保存中...',
                forbidClick:true,
                duraion:0
            })
            try{
                const localGender = this.localGender
                await changeUserProfileAPI({
                    gender:localGender
                }) 
                //更新视图
                this.$emit('input',localGender)
                //关闭图层
                this.$emit('close')
                //提示成功
                this.$toast.success('修改成功')
            }catch(error){
                console.log(error)
                this.$toast('更新失败')
            }
        },
        onChange(picker, value, index) {
            this.localGender = index
        },
    },
}
</script>

<style>

</style>