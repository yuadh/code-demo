<template>
  <div class="reply-commet">
    <!-- 顶部导航栏 -->
    <van-nav-bar 
     :title="comment.reply_count>0?`${comment.reply_count}条回复`:`暂无回复`">
      <van-icon
       slot="left"
       name="cross"
       @click="$emit('close')"/> 
    </van-nav-bar>
    <!-- 评论回复主体 -->
    <div class="reply-wrap">
      <commentItem :comment="comment"/>

      <van-cell title="全部回复"/>
      
      <commentList
       :list="datList"
       :artId="comment.com_id"
       type="c"
      />
    </div>
    <!-- 底部发布按钮 -->
    <div class="reply-button">
      <van-button
       class="write-btn"
       size="small"
       round
       @click="isPostShow = true">写评论</van-button>
    </div>
    <!-- 弹出层 -->
    <van-popup
     v-model="isPostShow"
     position="bottom">
      <commentPost
       :target="comment.com_id"
       @postSuccess="postSuccessFn"
       />
    </van-popup>
  </div>
</template>

<script>
import commentList from './comment-list.vue'
import commentPost from './comment-post.vue'
import commentItem from './comment-item.vue'
export default {
  data(){
    return{
      isPostShow:false,
      datList:[]
    }
  },
  props:{
    comment:{
      type:Object,
      required:true
    }
  },
  components:{
    commentList,
    commentPost,
    commentItem
  },
  created(){
    console.log(this.comment)

  },
  methods:{
    postSuccessFn(data){
      this.comment.reply_count++
      this.isPostShow = false
      this.datList.unshift(data.new_obj)
    }
  }
}
</script>

<style scoped lang="less">
  .reply-wrap{
    position: fixed;
    top:92px;
    left: 0;
    right: 0;
    bottom: 88px;
    overflow-y: auto;
  }
  .reply-button{
    position:fixed;
    right: 0;
    left: 0;
    bottom:0;
    height:88px;
    display: flex;
    justify-content: center;
    align-items: center;
    border-top: 1px solid #d8d8d8;
    .write-btn{
      width:60%;
    }
  }
</style>