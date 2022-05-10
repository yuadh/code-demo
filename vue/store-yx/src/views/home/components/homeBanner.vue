<template>
  <div class="homeBanner">
    <yxCarousel autoPlay :sliders="sliders"/>
  </div>
</template>

<script>
import yxCarousel from '@/components/library/yxCarousel.vue'
import { findBanner } from '@/api/home'
import { ref } from '@vue/reactivity'
export default {
  components:{
    yxCarousel
  },
  setup(){
    const sliders = ref([])
    findBanner().then(data=>{
      sliders.value = data.result
    })
    console.log('================')
    console.log(sliders)
    return {sliders}
  }
}
</script>

<style scoped lang="less">
  .homeBanner{
    width: 1240px;
    height: 500px;
    position: absolute;
    left: 0;
    top: 0;
    // z-index: 98;
  }
  .yxCarousel{
    :deep(.carousel-btn.prev){
      left: 270px;
    }
    :deep(.carousel-indicator){
      padding-left: 250px;
    }
  }
</style>