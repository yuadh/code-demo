<template>
  <header class="yxHeader">
    <div class="container">
      <!-- logo -->
      <h1 class="logo">
        <RouterLink to="/"></RouterLink>
      </h1>
      <!-- nav -->
      <yxHeaderNav/>
      <!-- search -->
      <div class="search">
        <i class="iconfont icon-search"></i>
        <input type="text" placeholder="搜一搜">
      </div>
      <yxHeaderCar />
    </div>
  </header>
</template>

<script>
import { computed } from '@vue/runtime-core'
import { useStore } from 'vuex'
import yxHeaderNav from './yxHeaderNav.vue'
import yxHeaderCar from './yxHeaderCar.vue'
export default {
  components:{
    yxHeaderNav,
    yxHeaderCar
  },
  setup(){
    const store =  useStore()
    const list = computed(()=>{
      return store.state.category.list
    })
    console.log('-----------------')
    console.log(list.value)
    return  {list}
  }
}
</script>

<style  lang="less">
  .yxHeader{
    background:#fff;
    .container{
      display: flex;
      align-items: center;
    }
    .logo{
      width: 200px;
      a{
        display: block;
        height: 132px;
        width: 100%;
        text-indent: -9999px;
        background: url(../assets/images/logo.png) no-repeat center 18px / contain;
      }
    }
    .search{
      width: 170px;
      height: 32px;
      position: relative;
      border-bottom: 1px solid #e7e7e7;
      line-height: 32px;
      .icon-search{
        font-size: 16px;
        padding-left: 5px;
        color: #666;
      }
      input{
        width: 140px;
        padding-left: 5px;
        color: #666;
      }
    }
    
  }
</style>