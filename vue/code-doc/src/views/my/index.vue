<template>
  <div class="my-container">
    <div class="header not-login">
      <div class="loginbtn" @click="$router.push('/login')">
        <img class="mobile-img" src="@/assets/logo.png">
        <span class="text"> 注册/登入</span>
      </div>
    </div>
    <div class="my-nav">
      
    </div>
  </div>
</template>

<script>
export default {

}
</script> 

<style lang="less" scoped>
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
  }
</style>