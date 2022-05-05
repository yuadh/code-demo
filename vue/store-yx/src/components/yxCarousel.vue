<template>
  <div class="yxCarousel" @mouseenter="stop()" @mouseleave="start()">
    <!-- 轮播图组件封装 -->
    <ul class="carouselBody">
      <li v-for="(obj,i) in 5" :key="i" class="carouselItem" :class="{fade:index===i}">
        <RouterLink to='/'>
          <img :src="require(`../assets/demo/${obj}.png`)">
        </RouterLink>
      </li>
    </ul>
    <!-- 按键 -->
    <a @click="toggle(-1)" href="javascript:;" class="carousel-btn prev"><i class="iconfont icon-angle-left"></i></a>
    <a @click="toggle(1)" href="javascript:;" class="carousel-btn next"><i class="iconfont icon-angle-right"></i></a>
    <!-- 指示器 -->
    <div class="carousel-indicator">
      <span @click="index=i" v-for="(obj,i) in 5" :key=i :class="{active:index===i}"></span>
    </div>
  </div>
  
</template>

<script>
import {ref} from 'vue'
import "@/assets/styles/common.less"
export default {
  setup(){
    const index = ref(0)
    const duration = ref(3000) //轮播时长
    const autoPlay = ref(true) //是否自动轮播
    let timer = null //定时器
    const toggle = (step)=>{
      const newIndex = index.value+step
      if(newIndex<0){
        index.value = 4
        return 
      }
      if(newIndex>4){
        index.value = 0
        return 
      }
      index.value = newIndex
    }
    const autoPlayFn = ()=>{
      clearInterval(timer)
      timer = setInterval(()=>{
        index.value++
        if(index.value>=5){
          index.value = 0
        }
      },duration.value)
    }
    //开始轮播
    const start = ()=>{
      if(autoPlay.value){
        autoPlayFn()
      }
    }
    //停止轮播
    const stop = ()=>{
      if(timer){
        clearInterval(timer)//如果有定时器就停止定时
      }
    }
    return {index,toggle,stop,start}
  }
}
</script>

<style scoped lang="less">
// 轮播图样式
.yxCarousel{
  // 填满父级容器
  // background-color: aqua;
  width: 100%;
  height: 100%;
  // 当父级容器小于这个值时会超出容器的大小
  min-width: 300px;
  min-height: 150px;
  position: relative;
  .carousel{
    &Body{
      width: 100%;
      height: 100%;
    }
    &Item{
      width: 100%;
      height: 100%;
      position: absolute;
      left: 0;
      top: 0;
      opacity: 0;
      transition: opacity .4s linear;//直线曲线运动
      &.fade{
        opacity: 1;
        z-index: 1;
      }
      img{
        width: 100%;
        height: 100%;
        object-fit: cover;
      }
    }
    &-indicator{
      position: absolute;
      left: 0;
      bottom: 20px;
      z-index: 2;
      width: 100%;
      text-align: center;
      span{
        display: inline-block;
        width: 12px;
        height: 12px;
        background: rgba(0,0,0,0.2);
        border-radius: 50%;
        cursor: pointer;
        ~ span{//less 剩余元素操作
          margin-left: 12px;
        }
        &.active{
          background: #fff;
        }       
      }
    }
    &-btn{
      width: 44px;
      height: 44px;
      background-color: rgba(0,0,0,0.2);
      border-radius: 50%;
      color: #fff;
      position: absolute;
      top: 228px;
      z-index: 2;
      text-align: center;
      line-height: 44px;
      opacity: 0;
      transition: all .5s;
      &.prev{
        left: 20px;
      }
      &.next{
        right:20px;
      }
    }
  }
  &:hover{
    .carousel-btn{
      opacity: 1;
    }
  }
}
</style>