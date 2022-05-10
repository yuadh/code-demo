<template>
  <!-- carticon -->
  <div class="cart">
    <RouterLink to="/" class="curr">
      <i class="iconfont icon-gouwuchecar"></i>
      <em>2</em>
    </RouterLink>
    <div class="layer"></div>
  </div>
</template>

<script>
export default {

}
</script>

<style lang="less">
  .cart{
    width: 50px;
    position: relative;
    z-index: 600;
    .curr{
      height: 32px;
      line-height: 32px;
      text-align: center;
      position: relative;
      display: block;
      .icon-gouwuchecar{
        font-size: 22px;
      }
    }
    em{
      font-style: normal;
      position: absolute;
      right: 4px;
      top: 0;
      padding: 1px 6px;
      line-height: 1;
      background: @helpColor;
      color: #fff;
      font-size: 12px;
      border-radius: 10px;
      font-family: Arial;
    }
  }
</style>