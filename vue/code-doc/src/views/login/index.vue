<template>
  <div>
    <!--导航条  -->
    <van-nav-bar class="doc-nav-bar" title="登录" />

    <!-- 表单验证 -->
    <!-- 触发事件前线进行表单验证 -->
    <van-form @submit="onSubmit">
        <van-field
          type="number"
          v-model="user.mobile"
          placeholder="请输入手机号"
          required
          clearable
          maxlength="11"
          rules="userFromRules.mobile"
        >
          <i slot='left-icon' class="doc doc-shouji"></i>
        </van-field>
        <van-field
          v-model="user.code"
          class="doc-yzm-warp"
          type="number"
          name="验证码"
          placeholder="请输入验证码"
          required
          maxlength="6"
          rules="userFromRules.code"
        >
          <i slot='left-icon' class="doc doc-yanzhengma"></i>
          <template #button>
            <van-button class="send-sms-btn"  round size="small" type="default">获取验证码</van-button>
          </template>
        </van-field>
      <div class="login-btn-warp">
        <van-button  class="login-btn" block type="info" native-type="submit">
          登录
        </van-button>
      </div>
    </van-form>
  </div>
</template>

<script>
import {loginAPI} from '@/api/index'
export default {
  data(){
    return {
      user: {
        mobile: '13911111111',
        code: '246810'
      },
      userFromRules:{
        // mobile项的一组校验规则
        mobile:[{
          // 是否为空校验
          required:true,
          message:'手机号不能为空'
        },{
          //是否为手机号格式校验
          pattern:/^1[3|5|7|8]\d{9}$/,
          message:'手机格式错误'
        }],
         code: [{
          required: true,
          message: '验证码不能为空'
        }, {
          pattern: /^\d{6}$/,
          message: '验证码格式错误'
        }]
      }
    }
  },
  methods: {
    async onSubmit(){
       this.$toast.loading({
        message: '登录中...',
        forbidClick: true, // 禁用背景点击
        duration: 0 // 持续时间，默认 2000，0 表示持续展示不关闭
      })
      // 实现基本的登入接口
      try{
        const res = await loginAPI(this.user)
        this.$toast.success('登录成功')
        console.log('登入成功',res)
      }catch(err){
        this.$toast.fail('失败文案');
        console.log('登入失败',err)
      }
    }
  }
}
</script>
    // 实现登入注册功能

<style  lang="less">
    /* 写样式 */
  .doc{
    font-size: 37px;
  }
  .send-sms-btn{
    width: 158px;
    height: 46px;
    /* 文字居中对齐 */
    line-height: 46px;
    background-color: #ededed;
    font-size: 22px;
    color: #666;
    margin-top: 0px;
    margin-bottom: 0.5px;
    /* margin-bottom: 6px; */
  }
  .doc-yanzhengma{
    display: inline-block;
    padding-top:5px ;
  }
  /* urgre */
  .doc-yzm-warp{
    line-height: 100%;
  }
  .login-btn-warp{
    padding: 53px 33px;
    .login-btn{
      background-color: #6db4fb;
      border: none;
    }
  }
</style>