import { findAllCategoryAPI } from "@/api/category"
import { topCategory } from "@/api/constants"


export default {
  namespaced: true,
  state () {
    return {
      // 将和后端返回分类数据一致的自定义分类数据转换为map
      list: topCategory.map(item=>({name:item}))
    }
  }
}
