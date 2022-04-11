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
        <van-grid-item 
        v-for="(obj,index) in myChannels" 
        :key="index" 
        class="grid-item"  
        @click="delUserChannel(obj,index)"
        >
            <van-icon
             v-show="isEdit&&!fiexdChannels.includes(obj.id)"
             name="clear"
             slot="icon"
            />
            <span slot="text" class="text" :class="{active:index===active}" >{{obj.name}}</span>
        </van-grid-item>
      </van-grid>

      <van-cell :border="false">
          <div slot="title" class="title-text">频道推荐</div>
      </van-cell>
       <van-grid class="recommend-grid" :gutter="10">
        <van-grid-item class="grid-item" icon="plus" 
        v-for="obj in recommendChannels" 
        :key="obj.id" 
        @click="addUserChannel(obj)"
        >
            <span slot="text" class="text">{{obj.name}}</span>
        </van-grid-item>
      </van-grid>
    </div>
</template>

<script>
import {getAllChannelsAPI,addUserChannelAPI,delUserChannelAPI} from '@/api/index'
import {mapState} from 'vuex'
import {setItem} from '@/utils/storage'
export default {
    props:{
        myChannels:{
            type:Array,
            required:true
        },
        active:{
            tyre:Number,
            required:true
        }
    },
    data(){
        return{
            allChannels:[],
            isEdit:false,
            fiexdChannels:[0,1],//非删除逻辑,需要配合后端
        }
    },
     computed:{
        ...mapState(['user']),
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
        },
        async addUserChannel(channel){
            this.myChannels.push(channel)//逻辑上加入我的频道
            if(this.user){
                try{
                    console.log(channel)
                    const dat = addUserChannelAPI({
                        id:channel.id,
                        seq:this.myChannels.length//上传服务器中覆盖的频道序号
                    })
                    console.log(dat);
                }catch(error){
                    console.log(error)
                    this.$toast('添加失败')
                }
            }else{
                console.log('本地添加')
                setItem('DOC_CHANNELS',this.myChannels)
            }
        },
        async delUserChannel(channel,index){
            if(this.isEdit){
                if(this.fiexdChannels.includes(channel.id)){
                    return  //如果是固定频道就不进行删除操作
                }
                // 注意，子父组件的通信在引用类型如数组，可以直接修改其值不通知组件，如果是
                // 普通类型就不能够直接修改其值如简单整数类型
                this.myChannels.splice(index,1)//删除指定索引元素
                if(this.active>=index){//如果待删除的频道在当前频道左边需要进行active左移处理
                    // 用户体验合理
                    this.$emit('updataActive',this.active-1,true)
                }
                // 线上处理
                try{
                    if(this.user){
                        await delUserChannelAPI(channel.id)
                    }else{
                        console.log('本地删除')
                        setItem('DOC_CHANNELS',this.myChannels)
                    }
                }catch(error){
                    console.log(error)
                    this.$toast('删除失败')
                }
            }else{
                //如果不是编辑状态就修改活动页面
                this.$emit("updataActive",index,false)
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