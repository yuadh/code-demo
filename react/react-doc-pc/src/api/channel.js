import request from 'utils/request'

export const getChannelAPI = () => {
  return request('/channels', 'get')
}
