<template>
  <div class="main">
    <div class="container">
      <yxCarousel/>
    </div>
  </div>
</template>

<script>
import  yxCarousel from '@/components/yxCarousel.vue'
export default {
  components: {
    yxCarousel
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
  background-color: aqua;
  .container{
    width: 1240px;
    height: 500px;
  }
}
</style>