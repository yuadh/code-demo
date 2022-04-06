<template>
    <div class="home-container">
     <van-nav-bar class="doc-nav-bar">
       <van-button 
       slot="title"
       size="small"
       round
       icon="search"
       class="search-btn"
       type="info">
        搜索
       </van-button>
     </van-nav-bar>

    <van-tabs class="channel-tabs" v-model="active" swipeable>
      <van-tab title="标签 1">内容 1</van-tab>
      <van-tab title="标签 2">内容 2</van-tab>
      <van-tab title="标签 3">内容 3</van-tab>
      <van-tab title="标签 4">内容 4</van-tab>
      <van-tab title="标签 5">内容 5</van-tab>
      <div
       slot="nav-right"
       class="hamburger-btn"
      >
        <i class="doc doc-gengduo"></i>
      </div>
    </van-tabs>

  </div>
</template>

<script>
import {getChannelsAPI} from '@/api/index'
export default {
  data() {
    return {
      active: 2,
    };
  },
  created () {
    
  }
}
</script>

<style lang="less" scoped>
  .home-container{
    .van-nav-bar__title {
      max-width: unset;
    }
    .search-btn{
      width: 400px;
      height: 64px;
      background-color: #5babfb;
      border: none;
      font-size: 28px;
      .van-icon{
        font-size: 32px;
      }
    }
    /deep/ .channel-tabs{
      .van-tab{
        border-right: 1px solid #edeff3;
        min-width: 200px;
        font-size: 30px;
        color: #777;
      }
    }
    .hamburger-btn{

    }
  }
</style>