<template>

  <yxTopNav/>
  <yxHeader/>
  <!-- 二级路由 -->
  <RouterView/>
</template>

<script>
import yxHeader from "@/components/yxHeader.vue"
import yxTopNav from "@/components/yxTopNav.vue"
import { useStore } from 'vuex'
export default {
  // 主页入口
  components:{
    yxHeader,
    yxTopNav
  },
  setup(){
    const store = useStore()
    store.dispatch('category/getList')
  }
}
</script>

<style>

</style>
