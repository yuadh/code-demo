//路由
import Vue from "vue"
import VueRouter from "vue-router"
import Home from "@/views/Home"
const routers=[
    {
        path:'/index',
        component:Home
    },
]
const router  = new VueRouter({
    routers
})
Vue.use(router)
export default router