// 对网络请求 axios 的二次封装

import axios from 'axios'
axios.defaults.baseURL = 'http://localhost:3000' //设置项目的基地址所有的网络请求都是基于这个地址
export default axios