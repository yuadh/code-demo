import request from "./request";

export const login = data => request({
    method: 'POST',
    url: '/v1_0/authorizations',
    data
})