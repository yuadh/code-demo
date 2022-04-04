import Vue from 'vue'
import Vuex from 'vuex'
import { setItem, getItem } from '@/utils/storage'
Vue.use(Vuex)
const CODEDOC_USER = 'CODEDOC_USER'
export default new Vuex.Store({
    state: {
        user: getItem(CODEDOC_USER)
    },
    getters: {},
    mutations: {
        setUser(state, user) {
            state.user = user
            setItem(CODEDOC_USER, state.user)
        }
    },
    actions: {},
    modules: {}
})