

import request from "@/utils/request"


export const findAllCategoryAPI =()=>{
  return request('/home/category/head','get')
}