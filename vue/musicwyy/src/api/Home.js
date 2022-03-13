//封装推荐歌单部分

import request from '@/utils/request'

export const recommendMusic = params => request({
    url:'/personalized',
    params
})
export const newMusic = params => request({
    url:'/personalized/newsong',
    params
})
