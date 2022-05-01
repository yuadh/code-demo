import request from "./request";


export const getArticles = (params) => request({
    method: 'GET',
    url: '/v1_0/articles',
    params
})

export const getArtText = params => request({
    method: 'GET',
    url: `/v1_0/articles/${params}`
})


export const getArtComments = params =>request({
    method:'GET',
    url:'/v1_0/comments',
    params
})
