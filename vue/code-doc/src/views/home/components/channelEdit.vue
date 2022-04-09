<template>
    <div class="channel-edit">
      <van-cell :border="false">
          <div slot="title" class="title-text">我的频道</div>
          <van-button
           class="edit-btn"
           type="danger"
           size="mini"
           round
           plain
           @click="isEdit=!isEdit"
           >
            {{isEdit?'完成':'编辑'}}
          </van-button>
      </van-cell>
      <van-grid class="my-grid" :gutter="10">
        <van-grid-item v-for="obj in myChannels" :key="obj.id" class="grid-item"  >
            <van-icon
             v-show="isEdit"
             name="clear"
             slot="icon"
            />
            <span slot="text" class="text">{{obj.name}}</span>
        </van-grid-item>
      </van-grid>

      <van-cell :border="false">
          <div slot="title" class="title-text">频道推荐</div>
      </van-cell>
       <van-grid class="recommend-grid" :gutter="10">
        <van-grid-item class="grid-item" icon="plus" 
        v-for="obj in recommendChannels" 
        :key="obj.id" >
            <span slot="text" class="text">{{obj.name}}</span>
        </van-grid-item>
      </van-grid>
    </div>
</template>

<script>
import {getAllChannelsAPI} from '@/api/index'
export default {
    props:{
        myChannels:{
            type:Array,
            required:true
        }
    },
    data(){
        return{
            allChannels:[],
            isEdit:false,

        }
    },
     computed:{
        recommendChannels(){
            //一个异步的请求在得到数据需要一些时间
            return this.allChannels.filter(channel=>{//返回一个不包含自己频道的新数组
                return !this.myChannels.find(mychannel=>{
                    return mychannel.id === channel.id //如果有相同频道返回该元素
                })
            })
        }
    },
    created () {
      this.loadAllChannels() 
    },
    methods:{
        async loadAllChannels(){
            try{
                const {data} = await getAllChannelsAPI();
                this.allChannels = data.data.channels
                console.log(this.allChannels)
            }catch(error){
                console.log(error)
                this.$toast('获取失败')
            }
        }
        
    },
    mounted(){
        console.log('mouted')
    }
}
</script>

<style lang="less" scoped>
    .channel-edit{
        padding: 85px 0;
        .title-text{
            font-size: 32px;
            color: #333;
        }
        .edit-btn{
            width: 104px;
            height: 48px;
            font-size: 26px;
            color:#f85959;
            border:1px solid #f85959
        }
        /deep/ .grid-item{
            width: 160px;
            height: 86px;
            .van-grid-item__content{
                white-space: nowrap;//不换行显示
                background-color: #f4f5f6;
                .text{
                    font-size: 28px;
                    color: #222;
                    margin-top: 0;
                }
                .active{
                    color:red;
                }
                .van-grid-item__icon-wrapper {
                    position: unset;
                }
            }
        }
        /deep/ .my-grid{
            .grid-item {
              .van-icon-clear {
                position: absolute;
                right: -10px;
                top: -10px;
                font-size: 30px;
                color:#cacaca;
                z-index: 2 ;
              }
            }
        }
        /deep/ .recommend-grid{
            .van-grid-item__content{
                flex-direction: row;
                .van-icon-plus{
                    font-size: 28px;
                    margin-right: 6px;
                }
            }
        }
    }
</style>