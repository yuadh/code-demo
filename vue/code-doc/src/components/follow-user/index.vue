<template>
  <van-button 
   v-if="isFollowed"
   class="follow-btn"
   round
   size="small"
   :loading="loading"
   @click="FollowerUserFn">
    已关注
  </van-button>
  <van-button 
   v-else
   class="follow-btn"
   round
   type="info"
   color="#3296fa"
   size="small"
   icon="plus" 
   :loading="loading"
   @click="FollowerUserFn"
   >关注</van-button>
</template>

<script>
import { followerUserAPI ,unFollowerUserAPI} from '@/api/index'
export default {
  model:{ //自定义 v-model 参数名和触发事件
    prop:'isFollowed',
    event:'is-Followed-State'
  },
  props:{
    isFollowed:{
      Type:Boolean,
      required:true
    },
    userId:{
      Type:[Number,String,Object],
      required:true
    },
  },
  data(){
    return{
      loading:false,
    }
  },
  created () {},
  mounted () {},
  methods:{
    async FollowerUserFn(){
      this.loading = true
      try{
        if(!this.isFollowed){//未关注执行函数
          console.log(typeof(this.userId))
          console.log(this.userId)
          const obj = await followerUserAPI(this.userId)
          console.log(obj)
        }else{  
          console.log(this.userId)
          const obj = await unFollowerUserAPI(this.userId)
          console.log(obj) 
        }
        this.$emit('is-Followed-State',!this.isFollowed)
      }catch(err){
        console.log(err)
        let mes = '操作失败'
        if(err.response && err.response.status == 400){
          mes = '不能关注自己'
        }
        this.$toast(mes)
      }
      this.loading = false
    }
  }
}
</script>

<style>

</style>