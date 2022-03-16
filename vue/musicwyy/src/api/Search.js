import request from '@/utils/request'

export const searchHot = () => request({
    url: '/search/hot'
})

export const cloudSearch = params=>request({
    url:'/cloudsearch',
    params
})