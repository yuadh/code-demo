<template>
  <van-button
   :icon="!collectSta?'star-o':'star'"
   :class="{collected:collectSta}"
   :loading="loading"
   @click = 'artCollectFn'
   />
</template>

<script>
import {collectArticleAPI,unCollectArticleAPI} from '@/api/index'
export default {
  data(){
    return{
      loading:false
    }
  },
  model:{
    prop:'collectSta',
    event:'is_Collect_Status'
  },
  props:{
    artId:{
      Type:[Number,String,Object],
      required:true
    },
    collectSta:{
      Type:Boolean,
      required:true
    }
  },
  methods:{
    async artCollectFn(){
      this.loading = true
      try{
        if(!this.collectSta){
          const obj = await collectArticleAPI(this.artId)
          console.log(obj)
        }else{
          const obj = await unCollectArticleAPI(this.artId)
          console.log(obj)
        }
        this.$toast.success(!this.collectSta?'收藏成功':'取消收藏')
        this.$emit('is_Collect_Status',!this.collectSta)
      }catch(err){
        console.log(err)
        this.$toast.fail('操作失败')
      }
      this.loading = false
    }
  }
}
</script>

<style lang="less">
  .collected{
    .van-icon{
      color:#ffa500
    }
  }
</style>