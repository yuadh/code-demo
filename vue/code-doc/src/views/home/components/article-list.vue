<template>
  <div class="list-container">
    <van-pull-refresh 
     v-model="isFreshLoading" 
     :success-text="refrenshTipText"
     success-duration=1400
     @refresh="onRefresh">
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
    </van-pull-refresh>
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
      isFreshLoading:false,
      refrenshTipText:'刷新成功'
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
          timestamp:this.timestamp||Date.now(),//添加到文章列表容易中的 新文章 
          with_top:0
        })
        const {results} = data.data
        this.list.push(...results) //添加的形式加到文章列表容器中
        this.loading = false 
        if(results.length){
          this.timestamp = data.data.pre_timestamp //更新时间戳 防止加入重复数据 后端处理逻辑
        }else{
          this.finished = true
        }
        console.log(this.list)
      }catch(error){
        this.error = true
        this.loading=false
      }
    },
    async onRefresh(){
      try{
          //刷新的数据类似于 百度贴吧 新帖子在上旧帖子在下
          //如需重新加载更多的新数据需要向下移动,或一直刷新
          //使用新时间戳获取一次新的数据 
          const {data} = await getArticlesAPI({
            channel_id:this.channel.id,
            timestamp:Date.now(),
            with_top:0
          })
          const {results} =data.data
          this.list.unshift(...results)
          
          this.isFreshLoading = false
          this.refrenshTipText = `刷新成功，更新了${results.length}条数据`
          console.log('刷新top')
          console.log(this.list)
      }catch(error){
        this.refrenshTipText = '刷新失败'
        this.isFreshLoading = false
      }
    }
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