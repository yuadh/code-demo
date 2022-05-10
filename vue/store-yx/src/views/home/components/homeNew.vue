<template>
  <div class="home-new">
    <homePanel title="新鲜好物" subTitle="新鲜出炉 品质靠谱">
      <template #right><yx-more/></template>
      <div style="position:relative;height:426px;">
        <ul v-if="goods.length" class="goods-list">
          <li v-for="item in goods" :key="item.id">
            <RouterLink to="/">
              <img :src="item.picture" alt="">
              <p class="name ellipsis">{{item.name}}</p>
              <p class="price">{{item.price}}</p>
            </RouterLink>
          </li>
        </ul>
      </div>
    </homePanel>
  </div>
</template>

<script>
import YxMore from '@/components/library/yxMore.vue'
import homePanel from './homePanel.vue'
import {getNewApi} from "@/api/home"
import { ref } from '@vue/reactivity'
export default {
  components:{
    homePanel,
    YxMore
  },
  setup(){
    const goods = ref([])
    getNewApi().then(data=>{
      goods.value = data.result
    }).catch(err=>{
      console.log(err)
    })
    console.log("-----------====")
    console.log(goods)
    return {goods}
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