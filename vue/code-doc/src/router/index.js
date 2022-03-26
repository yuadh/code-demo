import Vue from 'vue'
import VueRouter from 'vue-router'
Vue.use(VueRouter)

const routes = [
    {
        path: '/login',
        component: () =>
            import ('@/views/login')
    },
    {
        path:'/',
        component:()=>import ('@/views/layout'),
        children:[
            {
                path:'',
                name:'home',
                component:()=>import('@/views/home')
            },
            {
                path:'/my',
                name:'my',
                component:()=>import('@/views/my')
            }
        ]
    }
]

const router = new VueRouter({
    routes
})

export default router