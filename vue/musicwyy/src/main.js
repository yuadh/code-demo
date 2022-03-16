import Vue from 'vue'
import App from './App.vue'
import "@/mobile/flexible" // 适配
import "@/styles/reset.css" // 初始化样式
import router from '@/router'
import songItem from "@/components/songItem"
import {
    Button,
    NavBar,
    Tabbar,
    TabbarItem,
    Col,
    Row,
    Image as VanImage,
    Cell,
    Icon,
    Search,
    List
} from "vant"
import { recommendMusicAPI, newMusicAPI, searchHotAPI ,couldSearchAPI} from '@/api/index'
Vue.config.productionTip = false
Vue.use(Button)
Vue.use(NavBar)
Vue.use(Tabbar)
Vue.use(TabbarItem)
Vue.use(Col)
Vue.use(Row)
Vue.use(VanImage)
Vue.use(Cell)
Vue.use(Icon)
Vue.use(Search)
Vue.use(List)
Vue.component('songItem',songItem)


async function test() {
    const res = recommendMusicAPI({ limit: 20 })
    console.log(res)
}
test();

new Vue({
    router,
    render: h => h(App)
}).$mount('#app')