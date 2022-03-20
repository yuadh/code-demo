import Vue from 'vue'
import VueRouter from 'vue-router'
Vue.use(VueRouter)

const routes = [{
        path: '/my',
        component: () =>
            import ('@/views/my')
    },
    {
        path: '/home',
        compoennt: () =>
            import ('@/views/home')
    }
]

const router = new VueRouter({
    routes
})

export default router