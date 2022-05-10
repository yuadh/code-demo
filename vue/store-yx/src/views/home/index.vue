<template>
  <div style="height:1000px;background-color:pink;"></div>
  <div class="home-enther">
      <div class="container">
        <home-banner/>
        <div class="homeCategory"></div>
      </div>
  </div>
  <homeHot/>
  <div style="height:1000px;background-color:pink;"></div>
</template>

<script>
import { findBanner } from '@/api/home'
import homeBanner from './components/homeBanner.vue'
import homeHot from './components/homeHot.vue'
export default {
  components:{
    homeBanner,
    homeHot
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
