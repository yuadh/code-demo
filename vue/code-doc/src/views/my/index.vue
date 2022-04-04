<template>
  <div class="my-container">
    <div v-if="user" class="header user-info">
      <!-- 已登入展示页面 -->
      <div class="base-info">
        <div class="left">
          <van-image
            class="avatar"
            fit="cover"
            round
            :src="userInfo.photo"
          />
          <span class="name">{{userInfo.name}}</span>
        </div>
        <div class="right">
          <van-button 
            round
            size="mini"
            type="default"
            to="/user/profile"
          >
            编辑资料
          </van-button>
        </div>
      </div>
      <div class="data-stats">
        <div class="data-item">
          <span class="count">{{userInfo.art_count}}</span>
          <span class="text">头条</span>
        </div>
        <div class="data-item">
          <span class="count">{{userInfo.follow_count}}</span>
          <span class="text">关注</span>
        </div>
        <div class="data-item">
          <span class="count">{{userInfo.fans_count}}</span>
          <span class="text">粉丝</span>
        </div>
        <div class="data-item">
          <span class="count">{{userInfo.like_count}}</span>
          <span class="text">获赞</span>
        </div>
      </div>
    </div>
    <div v-else class="header not-login">
      <!-- 未登入展示页面 -->
      <div class="loginbtn" @click="$router.push('/login')">
        <img class="mobile-img" src="@/assets/mobile.png">
        <span class="text"> 登录 / 注册</span>
      </div>
    </div>
    <!-- <div class="my-nav"> -->
      <van-grid class="grid-nav mb9" :column-num="2" clickable>
        <van-grid-item class="grid-item">
          <i slot="icon" class="doc doc-shoucang"></i>
          <span slot="text" class="text">收藏</span>
        </van-grid-item>
        <van-grid-item class="grid-item">
          <i slot="icon" class="doc doc-lishi"></i>
          <span slot="text" class="text">历史</span>
        </van-grid-item>
      </van-grid>

      <!-- cell单元格 -->
      <van-cell title="消息通知"  is-link/>
      <van-cell class="mb9" title="客服服务" is-link />
      <!-- 退出登入按钮 -->
      <van-cell 
        v-if="user"
        class="logout-btn"
        title="退出登录"
        clickable
        @click="toLogout"
      />
    <!-- </div> -->
  </div>
</template>

<script>
import {mapState} from 'vuex'
import {getUserInfoAPI} from '@/api/index'
export default {
  
  data(){
    return {
      userInfo:{}
    }
  },
  computed:{
    ...mapState(['user'])
  },
  created () {
    // vue实例创建完成后 获取用户的登入信息 为挂载作准备
    if(this.user){
      this.loadUserInfo()
    }else{
      console.log('未执行')
    }
  },
  methods: {
    async loadUserInfo(){
      try{
        const {data} = await getUserInfoAPI()
        this.userInfo = data.data
        console.log(data)
        console.log('233')
      }catch(error){
        console.log('出错')
      }
    },
    toLogout(){
      this.$dialog.confirm({
        message: '确定退出吗',
      }).then(() => {
        // on confirm
        this.$store.commit('setUser', null)

      }).catch(() => {
        // on cancel

      });
    }
  }
}
</script> 

<style scoped lang="less">
  .my-container{
    .header{
      height: 361px;
      background: url('@/assets/banner.png') no-repeat;
      background-size: cover;
    }
    .not-login{
      display: flex;
      justify-content: center;
      align-items: center;
      .loginbtn{
        display: flex;
        flex-direction: column;//改变主轴
        justify-content: center;
        align-items: center;
        .mobile-img{
          width: 132px;
          height: 132px;
          margin-bottom: 15px;
        }
        .text{
          font-size: 28px;
          color:#fff;
        }
      }
    }
    .grid-nav{
      .grid-item{
        height: 141px;
        i.doc{
          font-size: 45px;
        }
        .doc-shoucang{
          color:#eb5253;
        }
        .doc-lishi{
          color:#ff9d1d;
        }
        span.text{
          font-size: 28px;
        }
      }
    }
    .user-info{
      .base-info{
        height: 231px;
        padding: 76px 32px 23px;
        box-sizing: border-box;
        display: flex;
        justify-content: space-between;
        align-items: center;
        .left{
          display: flex;
          align-items: center;
          .avatar{
            width: 132px;
            height: 132px;
            border: 4px solid #fff;
            margin-right: 23px;
          }
          .name{
            font-size: 30px;
            color: #fff;
          }
        }
      }
      .data-stats{
        display: flex;
        .data-item{
          height: 130px;
          flex: 1;
          display: flex;
          flex-direction: column;
          justify-content: center;
          align-items: center;
          color: #fff;
          .count{
            font-size: 36px;
          }
          .text{
            font-size: 23px;
          }
        }
      }
    }
   .logout-btn{
      text-align:center;
      color:#d86262;
    }
    .mb9{
      margin-bottom: 9px;
    }
  }
</style>