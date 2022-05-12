<template>
  <div class="home-product" ref="target">
    <homePanel  :title="item.name" v-for="item in list" :key="item.id">
      <template #right>
        <div class="sub">
          <RouterLink v-for="sub in item.children" :key="sub.id" to="/">
            {{sub.name}}
          </RouterLink>
        </div>
        <yxMore/>
      </template>
      <div class="box">
        <RouterLink class="cover" to="/">
          <img :src="item.picture">
          <strong class="label">
            <span>{{item.name}}馆</span>
            <span class="ellipsi">{{item.saleInfo}}</span>
          </strong>
        </RouterLink>
        <ul  class="goods-list">
          <li v-for="obj in item.goods" :key="obj.id">
            <homeGoods :item="obj"/>
          </li>
        </ul>
      </div>
    </homePanel>
  </div>
</template>

<script>
import homePanel from './homePanel.vue'
import yxMore from "@/components/library/yxMore"
import homeGoods from "./homeGoods"
import {getGoods} from "@/api/home"
import {useDataLazy} from '@/hooks/index.js'
import {ref} from "vue"
export default {
  components: {
    homePanel,
    yxMore,
    homeGoods
  },
  setup(){
    const list = ref([])
    const {target,result} = useDataLazy(getGoods)
    // getGoods().then(data=>{
    //   console.log("000000000000")
    //   console.log(data)
    //   list.value = data.result
    // }).catch(err=>{
    //   console.log(err)
    // })
    return {list:result,target}
  }
}
</script>

<style lang="less" scoped>
  .home-product{
    background:#fff;
    height: 2900px;
    .sub{
      margin-bottom: 2px;
      a{
        padding: 2px 12px;
        font-size: 16px;
        border-radius: 4px;
        &:hover{
          background:@xtxColor;
          color:#fff;
        }
        &:last-child{
          margin-right: 80px;
        }
      } 
    }
    .box{
      display: flex;
      .cover{
        height: 610px;
        width: 240px;
        margin-right: 10px;
        position: relative;
        img{
          width: 100%;
          height: 100%;
          object-fit: cover;
        }
        .label{
          width: 188px;
          height: 66px;
          display: flex;
          font-size: 18px;
          color: #fff;
          line-height: 66px;
          font-weight: normal;
          position: absolute;
          left: 0;
          top: 50%;
          transform: translate3d(0,-50%,0);
          span{
            text-align: center;
            &:first-child{
              width: 76px;
              background: rgba(0, 0, 0, .9);
            }
            &:last-child{
              flex: 1;
              background: rgba(0, 0, 0, .7);
            }
          }
        }
      }
      .goods-list{
        width: 990px;
        display: flex;
        flex-wrap: wrap;
        li{
          width: 240px;
          height: 300px;
          margin-right: 10px;
          margin-bottom: 10px;
          &:nth-last-child(-n+4){
            // 最后四个取消bottom边距
            margin-bottom: 0;
          }
          &:nth-child(4n){
            margin-right: 0;
          }
        }
      }
    }
  }
</style>