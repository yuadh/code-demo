<template>
  <!-- 头部通栏 -->
  <yxTopNav/>
  <!-- 头部导航 -->
  <yxHeader/>
  <!-- 吸顶导航 -->
  <yxheaderSticky/>
  <!-- 二级路由 -->
  <RouterView/>
</template>

<script>
import yxHeader from "@/components/yxHeader.vue"
import yxTopNav from "@/components/yxTopNav.vue"
import yxheaderSticky from "@/components/yxHeaderSticky.vue"
import { useStore } from 'vuex'
export default {
  // 主页入口
  components:{
    yxHeader,
    yxTopNav,
    yxheaderSticky
  },
  setup(){
    const store = useStore()
    store.dispatch('category/getList')
  }
}
</script>

<style>

</style>
