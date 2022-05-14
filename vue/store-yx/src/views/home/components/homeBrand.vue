<template>
  <homePanel title="热门品牌" sub-title="国际经典 品质保证">
    <template #right>
      <a @click="toggle(-1)" :class="{disabled:index===0}" href="javascript:;" class="iconfont icon-angle-left prev"></a>
      <a @click="toggle(1)" :class="{disabled:index===1}" href="javascript:;" class="iconfont icon-angle-right next"></a>
    </template>
    <div ref="target"  class="box">
      <Transition name="fade">
        <ul v-if="brands.length" class="list" :style="{transform:`translateX(${-index*1240}px)`}">
          <li v-for="item in brands" :key="item.id">
            <RouterLink to="\">
              <img :src="item.picture" alt="">
            </RouterLink>
          </li>
        </ul>
        <div v-else class="skeleton" :style="{transform:`translateX(${-index*1240}px)`}">
          <yxSkeleton class="item" v-for="i in 5" :key="i" bg="#e4e4e4" width="240px" height="305px" animated/>
        </div>
      </Transition>
    </div>
  </homePanel>
</template>

<script>
import {getHotBrand} from "@/api/home"
import yxSkeleton from "@/components/library/yxSkeleton.vue"
import homePanel from "./homePanel.vue"
import { ref } from 'vue-demi'
import {useDataLazy} from "@/hooks/index"
export default {
  components:{
    homePanel,
    yxSkeleton
  },
  setup(){
    const index =ref(0)
    const {result,target} = useDataLazy(getHotBrand)
    const toggle = (step)=>{
      const newIndex = index.value + step
      if(newIndex<0 || newIndex>1){
        return 
      }
      index.value = newIndex
    }
    return {index,toggle,brands:result,target}
  }
}
</script>

<style lang="less" scoped>
  .skeleton{
    width: 100%;
    display: flex;
    .item{
      margin-right: 10px;
      &:nth-child(5n){
        margin-right: 0;
      }
    }
  }
  .home-panel{
    background-color: #fff;
  }
  .iconfont{
    width: 20px;
    height: 20px;
    line-height: 20px;
    background: #ccc;
    color: #fff;
    display: inline-block;
    text-align: center;
    margin-left: 5px;
    background-color: @xtxColor;
    // &::before{
    //   font-size: 12px;
    //   position: relative;
    //   top: -2px;
    // }
    &.disabled{
      background: #ccc;
      cursor: not-allowed;
    }
  }
  .box{
    display: flex;
    width: 100%;
    height: 345px;
    overflow: hidden;
    padding-bottom: 40px;
    .list{
      width: 200%;
      display: flex;
      transition: all 1s;
      li {
        margin-right: 10px;
        width: 240px;
        &:nth-child(5n){
          margin-right: 0;
        }
        img{
          width: 240px;
          height: 305px;
        }
      }
    }
  }
</style>