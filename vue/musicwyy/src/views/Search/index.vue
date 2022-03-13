<template>
  <div>
      <!-- 搜索路由页面 -->
    <van-search
      v-model="value"
      shape="round"
      placeholder="请输入搜索关键词"
    />
    <div class="search_wrap">
      <!-- 标题 -->
      <p class="hot_title">热门搜索</p>
      <!-- 热搜关键词容器 -->
      <div class="hot_name_wrap">
        <!-- 每个搜索关键词 -->
        <span
          v-for="(obj,index) in hotArr"
          :key="index"
          class="hot_item"
          @click="func(obj.first)"
          >{{obj.first}}</span
        >
      </div>
    </div>
  </div>
</template>

<script>
import { searchHotAPI } from '@/api'
export default {

  data(){
    return{
      hotArr:[],
      value:"",
    }
  },
  // 绑定点击事件
  methods:{
    func(val){
      this.value=val
    }
  },
  async created(){
    const res =  await searchHotAPI(

    )
    console.log(res)
    this.hotArr = res.data.result.hots
  }
}
</script>

<style scoped>
/* 搜索容器的样式 */
.search_wrap {
  padding: 0.266667rem;
}

/*热门搜索文字标题样式 */
.hot_title {
  font-size: 0.32rem;
  color: #666;
}

/* 热搜词_容器 */
.hot_name_wrap {
  margin: 0.266667rem 0;
}

/* 热搜词_样式 */
.hot_item {
  display: inline-block;
  height: 0.853333rem;
  margin-right: 0.213333rem;
  margin-bottom: 0.213333rem;
  padding: 0 0.373333rem;
  font-size: 0.373333rem;
  line-height: 0.853333rem;
  color: #333;
  border-color: #d3d4da;
  border-radius: 0.853333rem;
  border: 1px solid #d3d4da;
}

/* 给单元格设置底部边框 */
.van-cell {
  border-bottom: 1px solid lightgray;
}
</style>