import request from 'utils/request'

export const userLoginApi = (mobile, code) => {
  return request('/authorizations', 'post', {
    mobile,
    code,
  })
}
