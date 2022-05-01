<template>
  <van-button
   :icon="artLikeSta==0? 'good-job-o' : 'good-job'"
   :class="{artLiked:artLikeSta==1}"
   :loading="loading"
   @click="likeArtFn"
   />
</template>

<script>
import {likeArtAPI,unLikeArtAPI} from "@/api/index"
export default {
    data(){
        return{
            loading:false
        }
    },
    model:{
        prop:'artLikeSta',
        event:'art-Like-Sta'
    },
    props:{
        artId:{
            Type:[Number,String,Object],
            required:true
        },  
        artLikeSta:{
            Type:[Number,String,Object],
            required:true
        },
    },
    methods:{
        async likeArtFn(){
            this.loading = true
            try{
                if(this.artLikeSta == 0){
                    const obj = await likeArtAPI(this.artId)
                    console.log(obj)
                }else{
                    const obj = await unLikeArtAPI(this.artId)
                    console.log(obj)
                }
                this.$emit('art-Like-Sta',this.artLikeSta==0?'1':'0')
                
                this.$toast.success(this.artLikeSta==0?'点赞成功':'取消点赞')
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
    .artLiked{
        .van-icon{
            color: #e5645f;
        }
    }
</style>