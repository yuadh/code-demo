<template>
  <van-cell class="comment-item">
    <!-- 头像 -->
    <van-image 
     class="avatar"
     fit="cover"
     round
     slot="icon"
     :src="comment.aut_photo"
     ></van-image>
    <!-- 用户名与点赞按钮 -->
    <div slot="title" class="title-wrap">
      <div class="user-name">{{comment.aut_name}}</div>
      <van-button
       :class="{liked:comment.is_liking}"
       class="like-btn"
       :icon='comment.is_liking?"good-job":"good-job-o"'
       :loading="commentLoading"
       @click='commentFn'
       >{{comment.like_count||'赞'}}</van-button>
    </div>
    <!-- 评论正文相关信息与回复按钮 -->
    <div slot="label">
      <p class="comment-content">{{comment.content}}</p>
      <div class="bottom-info">
        <span class="comment-pubdate">{{comment.pubdate|relativeTime}}</span>
        <van-button
         class="reply-btn"
         @click="$emit('replyClick',comment)"
         round>回复{{comment.reply_count}}</van-button>
      </div>
    </div>
  </van-cell>
</template>

<script>
import {likeCommentAPI,unLikeCommentAPI}  from '@/api/index'
export default {
  props:{
    comment:{
      type:Object,
      required:true
    }
  },
  data(){
    return{
      commentLoading:false
    }
  },
  created(){
    console.log(this.comment)
  },
  methods:{
    async commentFn(){
      this.commentLoading = true
      try{  
        if(!this.comment.is_liking){
          const obj = await likeCommentAPI(this.comment.com_id)
          console.log(obj)
          this.comment.like_count++
        }else{
          // 取消点赞
          const obj = await unLikeCommentAPI(this.comment.com_id)
          console.log(obj)
          this.comment.like_count--
        }
        this.comment.is_liking = !this.comment.is_liking
      }catch(err){
        console.log(err)
        this.$toast('操作失败')
      }
      this.commentLoading = false
    }
  }
}
</script>

<style scoped lang="less">
  .comment-item{
    .avatar{
      width: 72px;
      height: 72px;
      margin-right: 25px;
    }
    .title-wrap{
      display: flex;
      justify-content: space-between;
      align-items: center;
      .user-name{
        color:#406599;
        font-size: 26px;
      }
    }
    .comment-content{
      font-size: 32px;
      color: #222;
      word-break: break-all;
      text-align: justify;
    }
    .comment-pubdate{
      font-size: 19px;
      color: #222;
      margin-right: 25px;
    }
    .bottom-info{
      display: flex;
      align-items: center;
    }
    .reply-btn{
      height: 48px;
      line-height: 48px;
      font-size: 21px;
      color: #222;
    }
    .like-btn{
      height: 30px;
      padding: 0;
      border: 0;
      font-size: 19px;
      line-height: 30px;
      margin-right: 7px;
      .van-icon{
        font-size: 30px;
      }
      &.liked{
        color:#e5645f;
      }
    }
  }
</style>