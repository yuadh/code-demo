<template>
  <div class="article-container">
    <!-- 导航 -->
    <van-nav-bar
      title="code-doc"
      class="doc-nav-bar"
      left-arrow
      @click-left="$router.back()"
    />
    <!-- 主页及显示逻辑 -->
    <div class="main-wrap">
      <!-- 加载中显示模块 -->
      <div v-if="loading" class="loading-wrap">
         <van-loading
          color="#3296fa"
          vertical
        >加载中</van-loading>
      </div>

      <!-- 加载成功显示模块 -->
      <div v-else-if="article.title" class="article-main">
        <!-- 文章标题 -->
        <h1 class="article-title">{{article.title}}</h1>
        <!-- 用户信息 -->
        <van-cell class="user-info" cneter :border="false" >
          <van-image
            round
            class="avatar"
            slot="icon"
            fit="cover"
            :src="article.aut_photo"
          />
          <div class="username" slot="title">{{article.aut_name}}</div>
          <div class="public-date" slot="label">{{article.pubdate | relativeTime}}</div>
          <followuser 
           class="follow-btn"
           v-model="article.is_followed"
           :userId="article.aut_id"/>
        </van-cell>
        <!-- 文章主体 -->
        <div 
         class="article-content markdown-body"
         v-html="article.content"
         ref="article-content"></div>

        <van-divider>正文结束</van-divider>
        <!-- 文章评论列表 -->
        <commentList
         :artId="article.art_id"
         :list="commentList"
         @replyClick="replyFn"
         @success-loadComments="totalCommentCount = $event.total_count"/>
        <!-- 底部模块 -->
        <div class="article-bottom">
          <!-- 写评论 -->
          <van-button
           class="comment-btn"
           type="default"
           round 
           size="small"
           @click="isPostShow = true"
           >写评论</van-button>
          <!-- icon -->
          <van-icon 
           class="comment-icon"
           name="comment-o" 
           :badge="totalCommentCount" />      
          <!-- 收藏文章 -->
          <collectarticle
           v-model="article.is_collected"
           :artId="article.art_id"
           class="btn-item"/>
          <!-- 点赞文字 -->
          <likearticle
           v-model="article.like_count"
           :artId="article.art_id"
           class="btn-item"/>
          <!-- icon -->
          <van-icon name="share" color="#777777"/>
        </div>
        <!-- 评论发布弹出层 -->
        <van-popup
         v-model="isPostShow"
         position="bottom">
         <commentPost
          :target="article.art_id"
          @postSuccess="postSuccessFn" />
        </van-popup>

      </div>

      <!-- 加载404显示模块 -->
      <div v-else-if="errStatus===404" class="error-wrap">
        <van-icon name="failure" />
        <p class="text">该资源不存在或已删除</p>
      </div>

      <!-- 其它未知错误显示模块 -->
      <div v-else class="error-wrap">
        <van-icon name="failure" />
        <p class="text">内容加载失败</p>
        <van-button class="retry-btn">点击重试</van-button>
      </div>
    </div>
    <!-- 评论回复弹出层 -->
    <van-popup
     v-model="isReplyShow"
     style="height: 100%;"
     position="bottom">
     <!-- 虽然弹出层没有显示当时仍然存在，v-if减少渲染 -->
      <commentReply
       v-if="isReplyShow"
       :comment="currentComment"
       @close="isReplyShow=false"/>
    </van-popup>
  </div>
</template>

<script>
import {getArtTextAPI} from '@/api/index'
import followuser from '@/components/follow-user'
import likearticle from '@/components/like-article'
import collectarticle from '@/components/collect-article'
import commentList from './components/comment-list.vue'
import commentPost from './components/comment-post.vue'
import commentReply from './components/comment-reply.vue'
export default {
  data(){
    return{
      article:{},
      loading:true,
      errStatus:0,
      followLoading:false,
      totalCommentCount:0,
      isPostShow:false,
      commentList:[],
      isReplyShow:false,
      currentComment:{}
    }
  },
  provide:function(){//提供给子代使用的数据
    return {
      articleId:this.articleId
    }
  },
  props:{
    articleId:{
      required:true,
      type:[String,Number,Object]
    }
  },
  components:{
    followuser,
    likearticle,
    collectarticle,
    commentList,
    commentPost,
    commentReply
  },
  created(){
    this.loadArtText()
  },
  methods:{
    async loadArtText(){
      this.loading = true
      try{
        const {data} = await getArtTextAPI(this.articleId);
        this.article = data.data
        console.log(this.article)

        setTimeout(()=>{
          this.previewImage()
        },0)

      }catch(err){
        console.log(err)
        if(err.response && err.response.status===404){
          this.errStatus = 404
        }
      }
      this.loading=false
    },
    previewImage () {
      // 得到所有的 img 节点
      const articleContent = this.$refs['article-content']
      const imgs = articleContent.querySelectorAll('img')

      // 获取所有 img 地址
      const images = []
      imgs.forEach((img, index) => {
        images.push(img.src)

        // 给每个 img 注册点击事件，在处理函数中调用预览
        img.onclick = () => {
          ImagePreview({
            // 预览的图片地址数组
            images,
            // 起始位置，从 0 开始
            startPosition: index
          })
        }
      })
    },
    postSuccessFn(data){
      this.isPostShow = false
      this.commentList.unshift(data.new_obj) 
    },
    replyFn(comment){
      console.log('评论回复层弹出')
      this.currentComment = comment 
      this.isReplyShow = true
    }
  }
}
</script>

<style lang="less" scoped>
  @import './github-markdown.css';
  .article-container{
    .main-wrap{
      position:fixed;
      top:0;
      right:0;
      bottom:0;
      left: 0;
      background-color: #fff;
    }
    .article-main{
      position:fixed;
      left: 0;
      right: 0;
      top: 92px;
      bottom: 88px;
      overflow-y: scroll;
      background-color: #fff;
      .article-title{
        font-size: 40px;
        padding: 50px;
        margin: 0;
        color:#3a3a3a;
      }
      .user-info{
        padding: 0 32px;
        .avatar{
          width: 70px;
          height: 70px;
          margin-right: 17px;
        }
        .van-cell__label{
          margin-top: 0;
        }
        .user-name{
          font-size: 24px;
          color:#3a3a3a;
        }
        .public-date{
          font-size: 24px;
          color:#b7b7b7;
        }
        .follow-btn{
          width: 170px;
          height: 58px;
        }
      }
      .article-content{
        padding: 55px 32px;
        /deep/ p{
          text-align: justify;
        }
      }
    }
    .article-bottom{
      position:fixed;
      left: 0;
      right: 0;
      bottom: 0;
      display: flex;
      justify-content: space-around;
      align-items: center;
      box-sizing: border-box;
      height: 88px;
      border: 1px solid #d8d8d8;
      background-color: #fff;
      .comment-btn{
        width: 282px;
        height: 46px;
        border:2px solid #eee;
        font-size: 30px;
        line-height: 46px;
        color:#a7a7a7;
      }
      /deep/ .van-icon{
        font-size: 40px;
      }
      .comment-icon{
        top: 2px;
        color:#777;
        .van-info{
          font-size: 16px;
          background-color: #e22829;
        }
      }
      .btn-item{
        border:none;
        padding: 0;
        height: 40px;
        line-height: 40px;
        color:#777;
      }

    }
    .loading-wrap{
      padding:200px 32px;
      display: flex;
      align-items: center;
      justify-content: center;
      background-color: #fff;
    }
    .error-wrap{
      padding: 200px 32px;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      background-color: #fff;
      .van-icon{
        font-size: 122px;
        color:#b4b4b4;
      }
      .text{
        font-size: 30px;
        color:#666;
        margin:33px 0 46px;
      }
      .retry-btn{
        width:280px;
        height:70px;
        line-height: 70px;
        border:1px solid #c3c3c3;
        font-size: 30px;
        color:#666;
      }
    }
  }
</style>