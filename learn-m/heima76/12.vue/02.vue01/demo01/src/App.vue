<template>
  <div id="app">
    <div>
      <span>表单</span>
      <select v-model="from">
        <option value="江西">江西</option>
        <option value="湖南">湖南</option>
        <option value="四川">四川</option>
      </select>
      <div>
        <input type="checkbox" v-model="sdat" value="抽烟">抽烟
      <input type="checkbox" v-model="sdat" value="喝酒">喝酒
      <input type="checkbox" v-model="sdat" value="烫头">烫头
      </div>
      <div>
        <input type="radio" value="man" v-model="gt">男
        <input type="radio" value="woman" v-model="gt">女

      </div>
    </div>
  </div>
</template>

<script>

export default {
  data () {
    return {
      from:"测试",
      sdat:[],
      gt:"",
    }
  }
}
</script>

<style>
</style>
