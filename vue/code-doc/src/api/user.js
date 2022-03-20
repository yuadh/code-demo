import request from "./request";

export const login = () => request({
    method: 'GET',
    url: '/v1_0/search?q=its'
})