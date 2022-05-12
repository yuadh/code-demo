<template>
  <div style="height:1000px;background-color:pink;"></div>
  <yxSkeleton :animated="true" bg="red"/>
  <div class="home-enther">
      <div class="container">
        <home-banner/>
        <div class="homeCategory"></div>
      </div>
  </div>
  <homeNew/>
  <homeHot/>
  <homeProduct/>
  <div style="height:1000px;background-color:pink;"></div>
</template>

<script>
import { findBanner } from '@/api/home'
import homeBanner from './components/homeBanner.vue'
import homeHot from './components/homeHot.vue'
import homeNew from './components/homeNew.vue'
import homeProduct from './components/homeProduct.vue'
import yxSkeleton from '@/components/library/yxSkeleton'
export default {
  components:{
    homeBanner,
    homeHot,
    homeNew,
    homeProduct,
    yxSkeleton
  },
  setup () {
    // 测试接口是否可用
    findBanner().then(data => {
      console.log(data)
    })
  }
}
</script>

<style>
  .homeCategory{
    height:  500px;
  }
</style>
