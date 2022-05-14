<template>
  <homePanel title="最新专题">
    <template #right><yxMore/></template>
    <div ref="target" class="special-list">
      <div class="special-item" v-for="item in specialList" :key="item.id">
        <RouterLink to="/">
          <img v-lazy="item.cover" alt="">
          <div class="meta">
            <p class="title">
              <span class="top ellipsis">{{item.title}}</span>
              <span class="sub ellipsis">{{item.summary}}</span>
            </p>
            <span class="price">&yen;{{item.lowestPrice}}起</span>
          </div>
        </RouterLink>
        <div class="foot">
          <span class="like"><i class="iconfont icon-hart"/>{{item.collectNum}}</span>
          <span class="view"><i class="iconfont icon-icon-See"/>{{item.viewNum}}</span>
          <span class="reply"><i class="iconfont icon-message"/>{{item.replyNum}}</span>
        </div>
      </div>
    </div>
  </homePanel>
</template>

<script>
import homePanel from "./homePanel"
import {getSpecialAPI} from "@/api/home"
import yxMore from "@/components/library/yxMore.vue"
import {useDataLazy} from "@/hooks/index"
export default {
  components:{
    homePanel,
    yxMore
  },
  setup(){
    const {result,target}  = useDataLazy(getSpecialAPI)
    return {target,specialList:result}
  }
}
</script>

<style lang="less" scoped>
  .home-panel{
    background: #f5f5f5;
  }
  .special-list{
    height: 380px;
    padding-bottom: 20px;
    display: flex;
    justify-content: space-between;
    .special-item{
      width: 404px;
      background:#fff;
      .hoverShadow();
      a{
        display: block;
        width: 100%;
        height: 288px;
        position: relative;
        img{
          width: 100%;
          height: 100%;
          object-fit: cover;
        }
        .meta{
          background-image: linear-gradient(to top,rgba(0,0,0,.8),transparent 50%);
          position: absolute;
          left: 0;
          top: 0;
          width: 100%;
          height: 288px;
          .title{
            position:  absolute;
            bottom: 0;
            left: 0;
            padding-left: 16px;
            width: 70%;
            height: 70px;
            .top{
              color: #fff;
              font-size: 22px;
              display: block;
            }
            .sub{
              color: #999;
              font-size: 19px;
              display: block;
            }
          }
          .price{
            position: absolute;
            bottom: 25px;
            right: 16px;
            line-height: 1;
            padding: 4px 8px 4px 7px;
            color:@priceColor;
            font-size: 17px;
            background-color: #fff;
            border-radius: 2px;
          }
        }
      }
      .foot{
        height: 72px;
        line-height: 72px;
        padding: 0 20px;
        font-size: 16px;
        i{
          display: inline-block;
          width: 15px;
          height: 14px;
          margin-right: 5px;
          color: #999;
        }
        .like,
        .view{
          float: left;
          margin-right: 25px;
          vertical-align: middle;
        }
        .reply{
          float: right;
          vertical-align: middle;
        }
      }
    }
  }
</style>