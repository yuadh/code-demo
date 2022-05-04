import axios from "axios";
import store from "@/store";
import router from "@/router";

export const baseURL = 'http://pcapi-xiaotuxian-front-devtest.itheima.net/'

const instance = axios.create({
  baseURL,
  timeout:5000
})
// 请求拦截
instance.interceptors.request.use(config=>{
  console.log('请求拦截成功了')
  const {profile} = store.state.user
  if(profile.token){
    config.headers.Authorization = `Bearer ${profile.token}`
  }
  return config
},err=>{
  console.log('请求拦截失败了')
  return Promise.reject(err)
})


// 响应拦截
instance.interceptors.response.use(res=>res.data,err=>{
  if(err.response&&err.response.status==401){
    //清空无效登录信息
    store.commit('user/setUser',{})
    const fullPath = encodeURIComponent(router.currentRoute.value.fullPath)
    router.push('/login?redirectUrl='+fullPath)
  }
  return Promise.reject(err)
})


// 请求工具函数爆露
export default (url,method,submitData)=>{
 return instance({
  url,
  method,
  [method.toLowerCase() === 'get' ? 'params' : 'data']: submitData
 })
}