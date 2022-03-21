<template>
  <div id="app">
    <router-view/>
  </div>
</template>
<script>
import {loginAPI} from '@/api'
export default {
  name: 'App',
  methods:{
    async test(){
      //测试接口是否可用
      const res = await loginAPI();
      console.log(res)
    }
  }
}
</script>
<style scoped lang="less">

</style>
