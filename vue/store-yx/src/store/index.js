import { createStore } from 'vuex'
import createPersistedstate from 'vuex-persistedstate'
import cart from './modules/cart'
import user from './modules/user'
import category from './modules/category'
export default createStore({
  state: {},
  getters: {},
  mutations: {},
  actions: {},
  modules: {
    user,
    cart,
    category
  },
  // 持久化插件
  plugins: [
    createPersistedstate({
      key: 'store-yx',
      paths: ['user', 'cart']
    })
  ]
})
