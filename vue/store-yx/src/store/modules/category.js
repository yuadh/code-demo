import { findAllCategoryAPI } from "@/api/category"
import { topCategory } from "@/api/constants"


export default {
  namespaced: true,
  state () {
    return {
      // 将和后端返回分类数据一致的自定义分类数据转换为map
      list: topCategory.map(item=>({name:item}))
    }
  },
  mutations: {
    setList(state,payload){
      state.list = payload
    },
    show(state,id){
      const currCategory = state.list.find(item=>item.id===id)
      currCategory.open = true
    },
    hide(state,id){
      const currCategory = state.list.find(item=>item.id===id)
      currCategory.open = false
    }
  },
  actions: {
    async getList({commit}){
      const data = await findAllCategoryAPI()
      // data.result.forEach(top=>{
      //   top.open = false
      // })
      commit('setList',data.result)
    }
  }
}
