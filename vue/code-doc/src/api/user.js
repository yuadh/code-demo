import request from "./request";

export const login = data => request({
    method: 'POST',
    url: '/v1_0/authorizations',
    data
})

export const getCode = mobile =>request({
    method:'GET',
    // es6
    url:`/v1_0/sms/codes/${mobile}`
})