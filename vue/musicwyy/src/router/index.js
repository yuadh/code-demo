import Vue from 'vue'
import Home from '@/views/Home'
import Layout from "@/views/Layout"
import Search from '@/views/Search'
import Play from '@/views/Play'
import VueRouter from 'vue-router'
Vue.use(VueRouter)
const route = [{
        path: '/',
        redirect: '/layout/home',
    },
    {
        path: '/play',
        component: Play
    },
    {
        path: '/layout',
        component: Layout,
        children: [{
                path: 'home',
                component: Home,
                meta: {
                    title: "主页"
                }
            },
            {
                path: 'search',
                component: Search,
                meta: {
                    title: "搜索"
                }
            }
        ]
    }
]
const router = new VueRouter({
    routes: route //!!!
})
export default router