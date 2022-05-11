// 首页请求

import request from '@/utils/request'

export const findBanner = () => {
    return request('/home/banner', 'get')
}


export const getNewApi = () => {
    return request('/home/new', 'get')
}

export const getHotApi = () => {
    return request('/home/hot', 'get')
}

export const getGoods = () => {
    return request('/home/goods', 'get')
}