<template>
  <div class="list-container">
    <van-list
     v-model="loading"
     :finished="finished"
     finished-text="没有更多了"
     :error.sync="error"
     error-text="请求失败，点击重新加载"
     @load="onLoad"
    >
        <articleItem
         v-for="(obj,index) in list"
         :key="index"
         :article = "obj"
        />
    </van-list>

  </div>
</template>

<script>
import articleItem from '@/components/articleItem'
import {getArticlesAPI} from '@/api/index'
export default {
  name:'article-list',
  props:{
    channel:{
      type:[String,Object],
      required:true
    }
  },
  components:{
    articleItem
  },
  data() {
    return {
      list: [],
      loading: false,
      finished: false,
      error:false,
      timestamp:null,//时间戳
    };
  },
  created () {
  },
  methods: {
    async onLoad() {
      // 异步更新数据
      try{
          // 1.将获取的数据载入
        const {data} = await getArticlesAPI({
          channel_id:this.channel.id,
          timestamp:this.timestamp||new Date(),//添加到文章列表容易中的 新文章 
          with_top:0
        })
        console.log(this.timestamp)
        console.log(data)
        const {results} = data.data
        this.list.push(...results) //添加的形式加到文章列表容器中
        this.loading = false 
        console.log(results.length)
        if(results.length){
          this.timestamp = data.data.pre_timestamp //更新时间戳 防止加入重复数据 后端处理逻辑
          console.log(this.list)
        }else{
          this.finished = true
        }
      }catch(error){
        this.error = true
        this.loading=false
      }
    },
  },
};
</script>

<style scoped lang="less">
  .list-container{
    position: fixed;
    top: 180px;
    bottom: 100px;
    overflow-y: auto;
    right: 0;
    left: 0;
  }
</style>