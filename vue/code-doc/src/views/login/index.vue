<template>
  <div>
    <!--导航条  -->
    <van-nav-bar class="doc-nav-bar" title="登录" />

    <!-- 表单验证 -->
    <!-- 触发事件前线进行表单验证 -->
    <van-form ref="loginForm" @submit="onSubmit">
        <van-field
          type="number"
          name="mobile"
          v-model="user.mobile"
          placeholder="请输入手机号"
          clearable
          maxlength="11"
          :rules="userFromRules.mobile"
        >
          <i slot='left-icon' class="doc doc-shouji"></i>
        </van-field>
        <van-field
          v-model="user.code"
          class="doc-yzm-warp"
          type="number"
          name="code"
          placeholder="请输入验证码"
          clearable
          maxlength="6"
          :rules="userFromRules.code"
        >
          <i slot='left-icon' class="doc doc-yanzhengma"></i>
          <template #button>
            <!-- 表单内的标签会促发submit事件 -->
            <van-button 
            v-if="!isShowCountDown"
            class="send-sms-btn"  
            round
            size="small"
            native-type="button"
            @click="onSendSms"
            >获取验证码</van-button>
            <van-count-down 
            v-else
            @finish="isShowCountDown=false"
            :time="1*60*1000" 
            format="ss s" />
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
import {loginAPI,getCodeAPI} from '@/api/index'
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
      },
      isShowCountDown:false
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
        this.$store.commit('setUser',res.data.data)
        console.log('登入成功',res)
      }catch(err){
        if(err.response.status === 400){
          this.$toast.fail('手机号或验证码错误')
        }else{
          this.$toast.fail('未知错误')
        }
        console.log('登入失败',err)
      }
    },
    async onSendSms(){
      try{
        console.log('发生验证码按钮有效')
        //在登录表单提交之间，允许发送验证码提交只校验手机号码的格式
        await this.$refs.loginForm.validate('mobile')
      }catch(err){
        //手机表单验证失败 阻止发送请求
        return console.log('发送验证码表单验证失败',err)
      }
      // 表单验证成功后直接开始进入即使防止再次发送请求
      this.isShowCountDown=true
      try{
        await getCodeAPI(this.user.mobile)
        this.$toast('发送成功')
      }catch(err){
        this.isShowCountDown=false
        if(err.response.status ===  429){
          this.$toast('发送太频繁')
        }else{
          this.$toast('发送失败')
        }
        console.log('err'+err)
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