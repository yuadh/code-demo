/**
 * 封装 axios 请求模块
 */
// 对网络请求 axios 的二次封装

import axios from 'axios'
import jsonBig from 'json-bigint'
import store from '@/store'
import router from '@/router'
axios.defaults.baseURL = 'http://toutiao.itheima.net' //设置项目的基地址所有的网络请求都是基于这个地址

// 在响应拦截之前对数据进行处理，可能会有数据操过安全范围进行转换
axios.defaults.transformResponse=[function(data){
    try{
        return jsonBig.parse(data)
    }catch(err){
        return {}
    }
}]
// 添加请求拦截器
axios.interceptors.request.use(function (config) {
    // 在发送请求之前做些什么
    // 查看是否有用户token，如果有把用户token加上请求头
    const user = store.state.user
    if(user){
        config.headers.Authorization=`Bearer${user.token}`
    }
    return config;
  }, function (error) {
    // 对请求错误做些什么
    console.log("请求已被拦截，请求错误")
    return Promise.reject(error);
  });

// 添加响应拦截器
axios.interceptors.response.use(function (response) {
    // 2xx 范围内的状态码都会触发该函数。成功状态码下的响应拦截
    // 对响应数据做点什么
    return response;
  }, 
  async function (error) {
    // 超出 2xx 范围的状态码都会触发该函数。失败状态下的响应拦截
    // 对响应错误做点什么
    // 检验响应状态出错原因
    if(error.response&&error.response.status === 401){
        const user = store.state.user
        if(!user||!user.refresh_token){//如果没有用户刷新token需要重新登入
            router.back('/login')
            return 
        }
        try{
            const res = await axios({
                method:'PUT',
                path:'http://toutiao.itheima.net/v1_0/authorizations',
                Headers:{
                    Authorization:`Bearer${refresh_token}`
                }
            })//发送请求,刷新token
            console.log('刷新token成功')
            store.commit('setUser',{
                token:res.data.data.token,
                refresh_token:res.data.data.refresh_token
            })

        }catch(err){
            console.log('请求刷新token失败')
            router.back('/login')
        }
    }
    return Promise.reject(error);
  });


export default axios
