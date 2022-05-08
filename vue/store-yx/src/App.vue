<template>
  <yxTopNav/>
  <yxHeader/>
  <div class="main">
    <div class="test hoverShadow">test</div>
    <div class="container">
      <yxCarousel class="hoverShadow()"/>
    </div>
  </div>
</template>

<script>
import yxTopNav from "@/components/yxTopNav.vue"
import yxCarousel from '@/components/yxCarousel.vue'
import yxHeader from './components/yxHeader.vue'
export default {
  components: {
    yxCarousel,
    yxTopNav,
    yxHeader
  }
}
</script>

<style lang="less">
.main{
  width: 100%;
  height: 100vh;
  display: flex;
  align-items: center;
  justify-content: center;
  background-color: @priceColor;
  .container{
    .hoverShadow();
    width: 500px;
    height: 600px;
  }
  .test{
    .hoverShadow();
    width: 100px;
    height: 100px;
    background-color: @warnColor;
  }
}
</style>
