import axios from 'axios'
import { Toast } from 'antd-mobile'
export const baseURL = 'http://geek.itheima.net/v1_0/'
// import Toast from 'antd-mobile/es/components/toast'
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
    if (err.response) {
      Toast.show({
        icon: 'fail',
        content: err.response.data.message,
        duration: 1000,
      })
    } else {
      Toast.show({
        content: '网络繁忙,请稍后重试',
        duration: 1000,
      })
    }
    return Promise.reject(err)
  }
)

const request = (url, method, submitData) => {
  return instance({
    url,
    method,
    [method.toLowerCase() === 'get' ? 'params' : 'data']: submitData,
  })
}
// 请求工具函数爆露
export default request
