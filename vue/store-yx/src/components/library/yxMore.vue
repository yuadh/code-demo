<template>
  <RouterLink to="/" class="yx-more">
    <span>查看更多</span>
    <i class="iconfont icon-angle-right"/>
  </RouterLink>
</template>

<script>
export default {

}
</script>

<style lang="less" scoped>
  .yx-more{
    margin-bottom: 2px;
    span{
      font-size: 16px;
      vertical-align: middle;
      margin-right: 4px;
      color:#999;
    }
    i{
      font-size: 14px;
      vertical-align: middle;
      color:#ccc;
    }
    &:hover{
      span,i {
        color:@xtxColor;
      }
    }
  }
</style>