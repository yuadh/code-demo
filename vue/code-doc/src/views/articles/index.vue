<template>
  <div class="article-container">
<<<<<<< HEAD
=======
    <!-- 导航 -->
>>>>>>> b97ebde6f4833d62b41f8e02ffc5182a62076e59
    <van-nav-bar
      title="code-doc"
      class="doc-nav-bar"
      left-arrow
      @click-left="$router.back()"
    />
<<<<<<< HEAD
    <div class="main-warp">
      <!-- 显示逻辑 -->
      <!-- 1.文章载入——加载中的显示 -->
      <!-- 2.成功载入——正文文章的显示 -->
    </div>
=======
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
        <h1 class="article-title">XXXX</h1>
        <!-- 用户信息 -->
        <van-cell class="user-info" cneter :border="false" >
          <van-image
            round
            class="avatar"
            slot="icon"
            fit="cover"
            :src="require('../../assets/logo.png')"
          />
          <div class="username" slot="title">xxx</div>
          <div class="public-date" slot="label">xxx</div>
          <followuser class="follow-btn"/>
        </van-cell>
        <!-- 文章主体 -->
        <!-- 文章评论列表 -->
        <!-- 底部模块 -->
        <div class="article-bottom">
          <!-- 写评论 -->
          
          <!-- icon -->
          <!-- 收藏文章 -->
          <!-- 点赞文字 -->
          <!-- icon -->
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
>>>>>>> b97ebde6f4833d62b41f8e02ffc5182a62076e59
  </div>
</template>

<script>
import followuser from '@/components/follow-user'

export default {
  components:{
    followuser
  }

}
</script>

<style lang="less" scoped>
  .article-container{
    .main-wrap{
      position:fixed;
      top:0;
      right:0;
      bottom:0;
      left: 0;
      background-color: #fff;
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