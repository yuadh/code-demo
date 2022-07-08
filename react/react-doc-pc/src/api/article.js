import request from 'utils/request'

export const getArticlesAPI = (params) => {
  return request('/mp/articles', 'get', params)
}
