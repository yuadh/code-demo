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
      <!-- <div class="loading-wrap">
         <van-loading
          color="#3296fa"
          vertical
        >加载中</van-loading>
      </div> -->

      <!-- 加载成功显示模块 -->
      <div class="article-main">
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
        <commentList/>
        <!-- 底部模块 -->
        <div class="article-bottom">
          <!-- 写评论 -->
          <van-button
           class="comment-btn"
           type="default"
           round 
           size="small"
           >写评论</van-button>
          <!-- icon -->
          <van-icon 
           class="comment-icon"
           name="comment-o" 
           badge="9" />      
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

      </div>

      <!-- 加载404显示模块 -->
      <!-- <div class="error-wrap">
        <van-icon name="failure" />
        <p class="text">该资源不存在或已删除</p>
      </div> -->

      <!-- 其它未知错误显示模块 -->
      <!-- <div class="error-wrap">
        <van-icon name="failure" />
        <p class="text">内容加载失败</p>
        <van-button class="retry-btn">点击重试</van-button>
      </div> -->
    </div>
    <!-- 评论弹出层 -->
  </div>
</template>

<script>
import {getArtTextAPI} from '@/api/index'
import followuser from '@/components/follow-user'
import likearticle from '@/components/like-article'
import collectarticle from '@/components/collect-article'
import commentList from './components/comment-list.vue'
export default {
  data(){
    return{
      article:{}
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
    commentList
  },
  created(){
    this.loadArtText()
  },
  methods:{
    async loadArtText(){
      try{
        const {data} = await getArtTextAPI(this.articleId);
        this.article = data.data
        console.log(this.article)

      }catch(err){

      }
    },
    loadImage(){
      const artContent = this.$refs['article-content']
      const imgs = artContent.querySelectorAll('img')
      console.log(imgs)
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