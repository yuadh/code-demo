// 首页请求

import request from '@/utils/request'


export const findBanner = ()=>{
  return request('/home/banner','get')
}