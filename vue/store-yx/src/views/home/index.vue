<template>
  <!-- 首页入口 -->
  <div class="home-enther">
      <div class="container">
        <homeCategory/>
        <home-banner/>
      </div>
  </div>
  <!-- 新鲜好物 -->
  <homeNew/>
  <!-- 人气推荐 -->
  <homeHot/>
  <!-- 品牌专区 -->
  <homeBrand/>
  <!-- 商品区块 -->
  <homeProduct/>
  <!-- 最新专区 -->
  <homeSpecial/>
  <Transition name="fade">
    <homeSkeleton v-if="show" @click="show=!show"/>
  </Transition>
  <div style="height:1000px;background-color:pink;"></div>
</template>

<script>
import { findBanner } from '@/api/home'
import homeBanner from './components/homeBanner.vue'
import homeHot from './components/homeHot.vue'
import homeNew from './components/homeNew.vue'
import homeProduct from './components/homeProduct.vue'
import homeSkeleton from './components/homeSkeleton.vue'
import homeBrand from "./components/homeBrand.vue"
import homeSpecial from "./components/homeSpecial.vue"
import homeCategory from "./components/homeCategory.vue"
export default {
  components:{
    homeBanner,
    homeHot,
    homeNew,
    homeProduct,
    homeSkeleton,
    homeBrand,
    homeSpecial,
    homeCategory,
  },
  data(){
    return{
      show:true
    }
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
