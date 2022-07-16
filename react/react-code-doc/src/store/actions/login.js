import request from '@/utils/request'
import { removeToken, setToken } from '@/utils/storage'
export const sendCodeAPI = (mobile) => {
  return async () => {
    await request(`/sms/codes/${mobile}`, 'get')
  }
}

export const loginAPI = (data) => {
  return async (dispatch) => {
    const res = await request('/authorizations', 'post', data)
    dispatch(saveToken(res.data))
    setToken(res.data)
  }
}

export const saveToken = (payload) => {
  return {
    type: 'login/token',
    payload,
  }
}

export const logout = () => {
  return (dispatch) => {
    removeToken()
    dispatch({
      type: 'logout/logout',
    })
  }
}
