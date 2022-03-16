<template>
  <div>
      <!-- 搜索路由页面 -->
    <van-search
      v-model="value"
      shape="round"
      placeholder="请输入搜索关键词"
      @input="inputFn"
    />
    <div class="search_wrap" v-if="searchList.length === 0">
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
    <div class="search_wrap" v-else>
      <p class="hot_title">最佳匹配</p>
      <van-list
      v-model="loading"
      :finished="finished"
      finished-text="没有更多了"
      @load="onLoad"
      >
        <songItem
          v-for="(obj,index) in searchList"
          :key="index"
          :name = "obj.name"
          :author = "obj.ar[0].name"
          :id="obj.id"
        ></songItem>
        <!-- <van-cell
          center
          v-for="(obj,index) in searchList" :key="index"
          :title='obj.name'
          :label="obj.ar[0].name + ' - ' + obj.name"
        >
          <template #right-icon>
            <van-icon name="play-circle-o" size="0.6rem"/>
          </template>
        </van-cell> -->
      </van-list>
    </div>
  </div>
</template>

<script>
import { searchHotAPI } from '@/api'
import { cloudSearchAPI } from '@/api'
export default {

  data(){
    return{
      hotArr:[],
      searchList:[],
      value:"",
      loading:false, //是否在加载中，只有在false时才会出发加载事件
      finished:false,//数据是否全部加载完成
      page:1,
      timer:""
    }
  },
  // 绑定点击事件
  methods:{
    // 返回搜索列表
    async getListFn(){
      return await cloudSearchAPI({
        keywords:this.value,
        limit:20,
        offset:(this.page-1)*20
      })
    },
    async func(val){//热搜关键词搜索
      this.page = 1 //防止从新搜索时 搜索到的结果时偏移之后的
      this.loading = false  //新数据搜索 
      this.finished = false //新数据搜索
      this.value=val
      const res = await this.getListFn()
      console.log(res)
      this.searchList = res.data.result.songs
    },
    //加防抖功能，一定时间内若重复触发，则清除
    async inputFn(){
      this.page = 1
      if(this.timer) clearTimeout(this.timer)
      this.timer = setTimeout(async() => {
        this.finished = false
        this.loading = false
        if(this.value.length === 0){
            this.searchList=[]
            return //阻止网络请求，当搜索关键字为0时
        }
        const res = await this.getListFn()
        if(res.data.result.songs === undefined){
          this.searchList=[]
          return //提前结束，当搜索放回没有结果时
        }
        this.searchList = res.data.result.songs
      }, 900);
    },
    async onLoad(){
      this.page++
      const res = await this.getListFn()
      if(res.data.result.songs === undefined){
        this.finished = true
        this.loading = false
        return //没有数据，阻止显示
      }
      this.searchList = [...this.searchList,...res.data.result.songs]
      this.loading = false
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