<template>
  <div>
    <!--导航条  -->
    <van-nav-bar class="doc-nav-bar" title="登录" />

    <!-- 表单验证 -->
    <van-form @submit="onSubmit">
        <van-field
          name="用户名"
          placeholder="请输入手机号"
        >
          <i slot='left-icon' class="doc doc-shouji"></i>
        </van-field>
        <van-field
          type="password"
          name="验证码"
          placeholder="请输入验证码"
        >
          <i slot='left-icon' class="doc doc-yanzhengma"></i>
          <template #button>
            <van-button class="send-sms-btn"  round size="small" type="default">获取验证码</van-button>
          </template>
        </van-field>
      <div style="margin: 16px;">
        <van-button  block type="info" native-type="submit">
          提交
        </van-button>
      </div>
    </van-form>
  </div>
</template>

<script>
export default {

}
</script>
    // 实现登入注册功能

<style>
    /* 写样式 */
  .doc{
    font-size: 37px;
  }
  .send-sms-btn{
    width: 172px;
    height: 46px;
    margin-top:-10px ;
    /* 文字居中对齐 */
    line-height: 46px;
    background-color: #ededed;
    font-size: 22px;
    color: #666;
  }
  /* urgre */
  .doc-yanzhengma{
    padding-top: 1px;
    color: red;
  }
</style>