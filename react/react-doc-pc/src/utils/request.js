import axios from 'axios'

export const baseURL = 'http://geek.itheima.net/v1_0'

const instance = axios.create({
  baseURL,
  timeout: 5000,
})

// 请求拦截
instance.interceptors.request.use(
  (config) => {
    console.log('请求拦截成功了')
    return config
  },
  (err) => {
    console.log('请求拦截失败了')
    return Promise.reject(err)
  }
)

// 响应拦截
instance.interceptors.response.use(
  (res) => res.data,
  (err) => {
    if (err.response && err.response.status === 401) {
      // 清空无效登录信息
      console.log('401')
    }
    return Promise.reject(err)
  }
)

// 请求工具函数爆露
const request = (url, method, submitData) => {
  return instance({
    url,
    method,
    [method.toLowerCase() === 'get' ? 'params' : 'data']: submitData,
  })
}
export default request
