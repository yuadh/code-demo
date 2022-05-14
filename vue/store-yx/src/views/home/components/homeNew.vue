<template>
  <div class="home-new">
    <homePanel title="新鲜好物" subTitle="新鲜出炉 品质靠谱">
      <template #right><yx-more/></template>
      <div ref="target" style="position:relative;height:426px;">
        <Transition name="fade">
          <ul v-if="goods.length" class="goods-list">
            <li v-for="item in goods" :key="item.id">
              <RouterLink to="/">
                <img v-lazy="item.picture" alt="">
                <p class="name ellipsis">{{item.name}}</p>
                <p class="price">{{item.price}}</p>
              </RouterLink>
            </li>
          </ul>
          <homeSkeleton v-else bg="#f0f9f4"/>
        </Transition>
      </div>
    </homePanel>
  </div>
</template>

<script>
import YxMore from '@/components/library/yxMore.vue'
import homePanel from './homePanel.vue'
import {getNewApi} from "@/api/home"
import { ref } from '@vue/reactivity'
import homeSkeleton from "./homeSkeleton"
import {useDataLazy} from "@/hooks/index"
export default {
  components:{
    homePanel,
    YxMore,
    homeSkeleton
  },
  setup(){
    const goods = ref([])
    // getNewApi().then(data=>{
    //   goods.value = data.result
    // }).catch(err=>{
    //   console.log(err)
    // })
    const {result,target} = useDataLazy(getNewApi)
    return {goods:result,target}
  }
}
</script>

<style lang="less" scoped>
  .goods-list{
    display: flex;
    justify-content: space-between;
    height: 406px;
    li{
      width: 306px;
      height: 406px;
      background: #f0f9f4;
      .hoverShadow();
      img{
        width: 306px;
        height: 306px;
      }
      p{
        font-size: 22px;
        padding: 12px 30px 0 30px;
        text-align: center;
      }
      .price{
        color:@priceColor;
      }
    }
  }
</style>