export default {
  namespaced: true,
  state() {
    return {
      profile: {
        id: "",
        avatar: "",
        nikename: "",
        account: "",
        mobile: "",
        token: ""
      }
    }
  },
  mutations: {
    setUser(state, payload) {
      state.profile = payload
    }
  }
}