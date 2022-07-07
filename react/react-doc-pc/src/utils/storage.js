const TOKEN_KEY = 'jky-pc-token'

/**
 * 保存token
 * @param {*} token
 */
export const setToken = (token) => {
  localStorage.setItem(TOKEN_KEY, token)
}

/**
 * 移除token
 */
export const getToken = () => localStorage.getItem(TOKEN_KEY)

export const removeToken = () => {
  localStorage.removeItem(TOKEN_KEY)
}
export const hasToken = () => !!getToken()
