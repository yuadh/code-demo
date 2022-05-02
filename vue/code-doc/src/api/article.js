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


export const getArtComments = params => request({
    method: 'GET',
    url: '/v1_0/comments',
    params
})

export const likeComment = (target) => request({
    method: 'POST',
    url: '/v1_0/comment/likings',
    data: {
        target
    }
})

export const unLikeComment = (target) => request({
    method: 'DELETE',
    url: `/v1_0/comment/likings/${target}`
})

export const addComment = (data) => request({
    method: 'POST',
    url: '/v1_0/comments',
    data
})