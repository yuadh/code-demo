<template>
  <!-- nav -->
  <ul class="app-headers-navs">
    <li class="home"><RouterLink to="/">首页</RouterLink></li>
    <li v-for="item in list" :key="item.id">
      <RouterLink to="/">{{item.name}}</RouterLink>
      <!-- 弹出层 -->
      <div class="layar"></div>
    </li>
  </ul>
</template>

<script>
import { computed } from '@vue/runtime-core'
import { useStore } from 'vuex'
export default {
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

<style lang="less" >
 .app-headers-navs{
      width: 820px;
      display: flex;
      justify-content: space-around;
      padding-left: 40px;
      position: relative;
      z-index: 999;
      >li{
        margin-right: 40px;
        width: 38px;
        text-align: center;
        >a{
          font-size: 16px;
          line-height: 32px;
          height: 32px;
          display: inline-block;
        }
        &:hover{
          a{
            color:@xtxColor;
            border-bottom: 1px solid @xtxColor;
          }
        }
      }
    }
</style>