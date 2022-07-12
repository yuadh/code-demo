const TOKEN_KEY = 'jky-h5-token'

/**
 * 保存token
 * @param {*} token
 */
export const setToken = (token) => {
  return localStorage.setItem(TOKEN_KEY, JSON.stringify(token))
}

/**
 * 获取token
 */
export const getToken = () => {
  return JSON.parse(localStorage.getItem(TOKEN_KEY)) || {}
}
/**
 * 移除token
 */
export const removeToken = () => {
  return localStorage.removeItem(TOKEN_KEY)
}
export const hasToken = () => {
  return !!getToken()
}
