<template>
  <div class="home-container">
     <van-nav-bar class="doc-nav-bar">
       <van-button 
       slot="title"
       size="small"
       round
       icon="search"
       class="search-btn"
       type="info">
        搜索
       </van-button>
     </van-nav-bar>

    <van-tabs class="channel-tabs" v-model="active" swipeable>
      <van-tab v-for="obj in channels" :key="obj.id" :title="obj.name">
        <ArticleList
         :channel="obj"
        />
      </van-tab>
      <div class="placeholder" slot="nav-right"/>
      <div
       slot="nav-right"
       class="hamburger-btn"
       @click="isChannelEditShow = true"
      >
        <i class="doc doc-gengduo"></i>
      </div>
    </van-tabs>
    <van-popup 
    closeable
    position="bottom"
    close-icon-position="top-left"
    :style="{height:'100%'}"
    v-model="isChannelEditShow">
      <!-- 实现频道列表的编辑 -->
      <channelEdit
       :myChannels="channels"
      />
    </van-popup>
  </div>
</template>

<script>
import {mapState} from 'vuex'
import {getChannelsAPI} from '@/api/index'
import articlelist from './components/article-list'
import ArticleList from './components/article-list.vue'
import channelEdit from './components/channelEdit.vue'
export default {
  data() {
    return {
      active: 0,
      channels:[],
      isChannelEditShow:false,
    };
  },
  components:{
    ArticleList,
    channelEdit,
  },
  created () {
    this.loadChannels()
  },
  methods:{
    async loadChannels(){
      try{
        // 待处理 需要进行本地持久化处理
        let channels=[]
        if(this.user){
          console.log('用户频道')
          const {data} = await getChannelsAPI()
          channels = data.data.channels
          console.log(data)
        }else{
          // 发送无用户登入的默认频道
          console.log('无用户频道')
          const {data} = await getChannelsAPI()
          channels = data.data.channels
          console.log(data)
        }
        this.channels = channels
      }catch(error){
        console.log(error)
        this.$toast('获取频道失败')
      }
    }
  },
  computed:{
    ...mapState(['user'])
  }
}
</script>

<style lang="less" scoped>
  .home-container{
    .van-nav-bar__title {
      max-width: unset;
    }
    .search-btn{
      width: 400px;
      height: 64px;
      background-color: #5babfb;
      border: none;
      font-size: 28px;
      .van-icon{
        font-size: 32px;
      }
    }
    /deep/ .channel-tabs{
      .van-tab{
        border-right: 1px solid #edeff3;
        min-width: 200px;
        font-size: 30px;
        color: #777;

      }
      .van-tab--active {
        color:#333;
      }
      .van-tabs__nav {
        padding-bottom: 0;
      }
      .van-tabs__line{
        bottom: 8px;
        width:31px;
        height: 8px;
        background-color: #3296fa;
      }
      .placeholder{
        flex-shrink: 0;
        width: 66px;
        height: 82px;
      }
      .hamburger-btn{
        position: fixed;
        right: 0;
        display: flex;
        justify-content: center;
        align-items: center;
        width: 66px;
        height: 82px;
        background-color: #fff;
        background-color: rgba(255, 255, 255, 0.902);
        i.doc{
          font-size: 33px;
        }

      }
    }
  }
</style>