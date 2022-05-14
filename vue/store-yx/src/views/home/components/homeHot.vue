<template>
  <div class="home-hot">
    <homePanel title="人气推荐" subTitle="人气爆款 不容错过">
      <div ref="target" style="position:relative;height:426px">
        <Transition name="fade">
          <ul v-if="list.length" class="goods-list">
            <li v-for="item in list" :key="item.id">
              <img v-lazy="item.picture" alt="">
              <p class="name">{{item.title}}</p>
              <p class="desc">{{item.alt}}</p>
            </li>
          </ul>
          <homeSkeleton v-else/>
        </Transition>
      </div>      
    </homePanel>
  </div>
</template>

<script>

import homePanel from './homePanel.vue'
import yxMore from '@/components/library/yxMore.vue'
import {getHotApi} from '@/api/home'
import { ref } from '@vue/reactivity'
import homeSkeleton from "./homeSkeleton.vue"
import {useDataLazy} from '@/hooks/index'
export default {
  components: {
    homePanel,
    yxMore,
    homeSkeleton
  },
  setup(){
    const list = ref([])
    // getHotApi().then(data=>{
    //   list.value = data.result
    // }).catch(err=>{
    //   console.log(err)
    // })
    const {result,target} = useDataLazy(getHotApi)
    return {list:result,target}
  }
}
</script>

<style scoped lang="less">
  .goods-list{
    display: flex;
    justify-content: space-between;
    height: 426px;
    li{
      width: 306px;
      height: 406px;
      .hoverShadow();
      img{
        width:306px;
        height: 306;
      }
      p{
        font-size: 22px;
        padding-top: 12px;
        text-align: center;
      }
      .desc{
        color: #999;
        font-size: 18px;
      }
    }
  }
</style>