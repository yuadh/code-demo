<template>
  <div class="wrap-main">
    <el-card class="check-main">
      <el-form :model="loginForm" :rules="loginRules" style="margin-top:50px">
        <el-form-item prop="mobile">
          <el-input v-model="loginForm.mobile" placeholder="输入手机号"></el-input>
        </el-form-item>
        <el-form-item prop="password">
          <el-input v-model="loginForm.password" placeholder="输入密码" ></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" style="width:100%;">登录</el-button>
        </el-form-item>
      </el-form>
    </el-card>
  </div>
</template>

<script>
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import Vue from 'vue';
Vue.use(ElementUI)
export default {
  data () {
    const checkMobile = function(rule,value,callback){
      value.charAt(2) === "9" ?callback():callback(new Error('手机第三位必须为9')) 
    }
    return {
      // 表单数据对象-根据官网示例
      loginForm:{
        mobile:'',
        password:''
      },
      loginRules:{
        mobile:[
          {required:true,message:'手机号不能为空',trigger:'blur'},
          {pattern:/^1[3-9]\d{9}$/,message:'手机格式不正确',trigger:'blur'},
          {trigger:'blur',validator:checkMobile}
        ],
        password:[
          {required:true,message:'密码不能为空',trigger:'blur'},
          {min:6,max:16,trigger:'blur',message:'密码长度为6-16位'}
        ]
      }
    }
  }
}
</script>

<style>
  .wrap-main{
    margin-top: 0;
    width: 100%;
    height: 100vh;
    background: pink;
    display: flex;
    justify-content: center;
    align-items: center;
  }
  .check-main{
    width: 440px;
    height: 330px;

  }
</style>