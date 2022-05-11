<template>
  <div class="home-product">
    <homePanel >
      <template #right>
        <div class="sub">
          <RouterLink v-for="i in 9" :key="i" to="/">
            XXX
          </RouterLink>
          <yxMore/>
        </div>
      </template>
      <div class="box">
        <RouterLink class="cover" to="/">
          <img src="/">
          <strong class="label">
            <span>XXX</span>
            <span>xxx</span>
          </strong>
        </RouterLink>
        <ul  class="goods-list">
          <li v-for="i in 6" :key="i">
            <homeGoods/>
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
export default {
  components: {
    homePanel,
    yxMore,
    homeGoods
},

}
</script>

<style lang="less" scoped>
  .home-product{
    background:#fff;
    height: 2900px;
    
  }
</style>