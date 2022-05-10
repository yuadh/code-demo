<template>
  <div style="height:1000px;background-color:pink;"></div>
  <div class="container">
    <home-banner/>
  </div>
  <div style="height:1000px;background-color:pink;"></div>
</template>

<script>
import { findBanner } from '@/api/home'
import homeBanner from './components/homeBanner.vue'
export default {
  components:{
    homeBanner
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

</style>
