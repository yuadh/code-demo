import request from '@/utils/request'

export const searchHot = () => request({
    url: '/search/hot'
})