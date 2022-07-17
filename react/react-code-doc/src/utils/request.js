import axios from 'axios'
import { Toast } from 'antd-mobile'
import { getToken, hasToken } from './storage'
import history from './history'
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
    const token = getToken().token
    console.log(token)
    if (token) {
      config.headers.Authorization = `Bearer ${token}`
    }
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
    if (!err.response) {
      Toast.show({
        content: '网络繁忙,请稍后重试',
        duration: 1000,
      })
    }
    const { response } = err
    // 非token类型的其它错误
    if (response.status !== 401) {
      Toast.show({
        icon: 'fail',
        content: err.response.data.message,
        duration: 1000,
      })
    }
    const { refresh_token } = getToken()
    // 如果没有 refresh_token
    if (!refresh_token) {
      history.push({
        pathname: '/login',
        state: {
          from: history.location.pathname,
        },
      })
      return Promise.reject(err)
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
