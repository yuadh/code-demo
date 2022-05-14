<template>
  <div class="home-skeleton container">
    <div class="item" v-for="i in 4" :key="i" :style="{backgroundColor:bg}">
      <yxSkeleton bg = "#e4e4e4" width="306px" height="306px" animated/>
      <yxSkeleton bg = "#e4e4e4" width="160px" height="24px" animated/>
      <yxSkeleton bg = "#e4e4e4" width="120px" height="24px" animated/>
    </div>
  </div>
</template>

<script>
import yxSkeleton from "@/components/library/yxSkeleton"
export default {
  components:{
    yxSkeleton
  },
  props:{
    bg:{
      type:String,
      default:'#fff'
    }
  }
}
</script>

<style lang="less">
  .home-skeleton{
    width: 1240px;
    height: 406px;
    display: flex;
    justify-content: space-between;
    .item{
      width: 306px;
      .yxSkeleton ~ .yxSkeleton{
        display: block;
        margin: 16px auto 0;
      }
    }
  }
</style>