<template>
  <div id="app">
    <h1>黑马头条</h1>
    <van-button @click="test" type="primary">主要按钮</van-button>
    <van-button type="success">成功按钮</van-button>
    <van-button type="default">默认按钮</van-button>
    <van-button type="warning">警告按钮</van-button>
    <van-button type="danger">危险按钮</van-button>
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
