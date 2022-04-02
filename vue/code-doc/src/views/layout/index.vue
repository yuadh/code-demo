<template>
   <div class="layout-container">
      <router-view></router-view>
      <van-tabbar class="layout-tabber" v-model="active">
         <van-tabbar-item to="/">
            <i slot="icon" class="doc doc-shouye"></i>
            <span>首页</span>
         </van-tabbar-item>
         <van-tabbar-item >
            <i slot="icon" class=" doc doc-wenda"></i>
            <span>问答</span>
         </van-tabbar-item>
         <van-tabbar-item >
            <i slot="icon" class="doc doc-shipin"></i>
            <span>视频</span>
         </van-tabbar-item>
         <van-tabbar-item to="/my">
            <i slot="icon" class="doc doc-wode"></i>
            <span>我的</span>
         </van-tabbar-item>
      </van-tabbar>
   </div>
</template>

<script>
export default {
   data() {
    return {
      active: 0,
    };
   },
}
</script>

<style lang="less" scoped>
.layout-container{
   .layout-tabber{
      i.doc{
         font-size: 40px;
      }
      span.text{
         font-size: 20px;
      }
   }
}
</style>