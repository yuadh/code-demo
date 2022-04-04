<template>
  <div>
      <van-datetime-picker
       v-model="currentDate"
       type="date"
       :min-date="minDate"
       :max-date="maxDate"
       @cancel="$emit('close')"
       @confirm="toConfirm"
       />
  </div>
</template>

<script>
import {changeUserProfileAPI} from '@/api/index'
import dayjs from 'dayjs'
export default {
    name:'updataBrithday',
    props:{
        value:{
            type: String,
            required:true
        }
    },
    data() {
      return {
        minDate: new Date(1970, 0, 1),
        maxDate: new Date(),
        currentDate: new Date(this.value),
      };
    },
    methods:{
        async toConfirm(){
            this.$toast.loading({
                message: '保存中...',
                forbidClick: true, // 禁止背景点击
                duration: 0 // 持续展示
            })
            try{
                console.log(this.currentDate)
                const localBrithday = dayjs(this.currentDate).format('YYYY-MM-DD')
                console.log(localBrithday)
                await changeUserProfileAPI({
                    birthday:localBrithday

                }) 
                //更新视图
                this.$emit('input', localBrithday)
                //关闭弹层
                this.$emit('close')
                //提示
                 this.$toast.success('更新成功')
            }catch(error){
                console.log(error)
                this.$toast('更新失败')
            }
        }
    }
}
</script>

<style>

</style>