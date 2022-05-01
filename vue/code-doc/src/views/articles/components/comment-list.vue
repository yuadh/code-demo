<template>
  <van-list
   v-model="loading"
   :finished="finished"
   finished-text="没有更多了"
   @load="onLoad">
    <commentItem/>
  </van-list>
</template>

<script>
import commentItem from "./comment-item.vue"
export default {
    components:{
        commentItem
    }
}
</script>

<style>

</style>