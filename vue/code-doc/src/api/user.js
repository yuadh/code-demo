import request from "./request";

export const login = data => request({
    method: 'POST',
    url: '/v1_0/authorizations',
    data
})

export const getCode = mobile => request({
    method: 'GET',
    // es6
    url: `/v1_0/sms/codes/${mobile}`
})
export const getUserInfo = () => request({
    method: 'GET',
    url: '/v1_0/user'
        // 请求拦截自动加上了用户认证
})

export const getUserProfile = () => request({
    method: 'GET',
    url: '/v1_0/user/profile'
})

export const changeUserProfile = (data) => request({
    method: 'PATCH',
    url: '/v1_0/user/profile',
    data
})

export const changeUserPhoto = (data) => request({
    method: 'PATCH',
    url: '/v1_0/user/photo',
    data
})

export const getChannels = () => request({
    method: 'GET',
    url: '/v1_0/user/channels'
})

export const getAllChannels = () => request({
    method: 'GET',
    url: '/v1_0/channels'
})