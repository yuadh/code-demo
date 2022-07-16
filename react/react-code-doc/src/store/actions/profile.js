import request from '@/utils/request'

export const getProfileAPI = () => {
  return async (dispatch) => {
    const res = await request('/user', 'get')
    console.log(res)
    dispatch(setUser(res.data))
  }
}
export const setUser = (payload) => {
  return {
    type: 'profile/user',
    payload,
  }
}
export const setProfile = (payload) => {
  return {
    type: 'profile/profile',
    payload,
  }
}
export const getProfileDetailsAPI = () => {
  return async (dispatch) => {
    const res = await request('/user/profile', 'get')
    console.log(res)
    dispatch(setProfile(res.data))
  }
}

export const updateProfile = (date) => {
  return async (dispatch) => {
    const res = await request('/user/profile', 'patch', date)
    console.log(res)
    dispatch(getProfileDetailsAPI())
  }
}

export const updatePhoto = (fd) => {
  return async (dispatch) => {
    const res = await request('/user/photo', 'patch', fd)
    console.log(res)
    dispatch(getProfileDetailsAPI())
  }
}
