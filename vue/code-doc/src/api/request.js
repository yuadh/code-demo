/**
 * 封装 axios 请求模块
 */
// 对网络请求 axios 的二次封装

import axios from 'axios'
axios.defaults.baseURL = 'http://toutiao.itheima.net' //设置项目的基地址所有的网络请求都是基于这个地址
export default axios
// import axios from "axios"

// const request = axios.create({ //对axios的二次封装
//     baseURL: "http://ttapi.research.itcast.cn" // 基础路径
// })

// export default request