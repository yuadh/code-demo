<template>
  <div>
      <van-nav-bar
      :title="activeTitle"
      left-text="返回"
      left-arrow
      border
      />
      <div class="main">
        <!-- 二级导航 -->
      <router-view></router-view>
      </div>
      <van-tabbar>
        <van-tabbar-item replace to="/layout/home" name="home" icon="home-o">主页</van-tabbar-item>
        <van-tabbar-item replace to="/layout/search" name="search" icon="search">搜索</van-tabbar-item>
        <van-tabbar-item name="friends" icon="friends-o">标签</van-tabbar-item>
        <van-tabbar-item name="setting" icon="setting-o">标签</van-tabbar-item>
      </van-tabbar>
  </div>
</template>

<script>
export default {
  data(){
    return{
      activeTitle:this.$route.meta.title
    }
  },
  watch:{
    $route(){
      this.activeTitle = this.$route.meta.title
    }
  }
}
</script>

<style scoped>
/* 中间内容区域 - 容器样式(留好上下导航所占位置) */
.main {
  padding-top: 46px;
  padding-bottom: 50px;
}
</style>