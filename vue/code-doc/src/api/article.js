import request from "./request";


export const getArticles = (params) => request({
    method: 'GET',
    url: '/v1_0/articles',
    params
})