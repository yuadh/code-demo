<template>
  <div class="comment-post">
    <van-field
     class="post-field"
     v-model.trim="message"
     rows="2"
     autosize
     type="textarea"
     maxlength="50"
     placeholder="请输入留言"
     show-word-limit
     />
    <van-button
     class="post-btn"
     @click="postFn"
     :disabled="!message.length">发布</van-button>
  </div>
</template>

<script>
import {addCommentAPI} from '@/api/index'
export default {
    inject:{//子代接收器 接收夫组件给子组件的数据
      articleId:{
        type:[Number,String,Object],
        default:null
      }
    },
    props:{
      target:{
        type:[Number,String,Object],
        required:true
      }
    },
    created(){
      console.log(this.articleId ? this.articleId.toString() : this.articleId)
      console.log( typeof(this.target))
    },
    data(){
      return {
        message:''
      }
    },
    methods:{
      async postFn(){
        this.$toast.loading({
          message:'发布中...',
          forbidClick:true,
          duration:0 //持续时间为直到发送请求完成或catch
        })
        try{
          const {data} = await addCommentAPI({
            target:this.target.toString(),
            content:this.message,
            art_id: this.articleId ? this.articleId.toString() : this.articleId
          })
          console.log(data)
          this.$emit('postSuccess',data.data)
          this.message = ''
          this.$toast.success('发布成功')

        }catch(err){
          console.log(err)
          this.$toast.fail('操作失败')
        }
      }
    }
}
</script>

<style scoped lang="less">
  .comment-post{
    display: flex;
    align-items: center;
    padding: 32px 0px 32px 32px;
    .post-field{
      background-color: #f5f7f9;
    }
    .post-btn{
      width:150px;
      border: none;
      padding: 0;
      color:#6ba3d8;
      // &::before{
      //   display: none;
      // }
    }
  }
</style>