<template>
  <div>home主页路由测试</div>
</template>

<script>
import { findBanner } from '@/api/home'
export default {
  setup () {
    // 测试接口是否可用
    findBanner().then(data => {
      console.log(data)
    })
  }
}
</script>

<style>

</style>
