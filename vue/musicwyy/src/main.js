import Vue from 'vue'
import App from './App.vue'
import router from '@/router'
import {Button,NavBar,Tabbar, TabbarItem,Col,Row,Image as VanImage} from "vant"
import {recommendMusicAPI,newMusicAPI} from '@/api/index'
Vue.config.productionTip = false
Vue.use(Button)
Vue.use(NavBar)
Vue.use(Tabbar)
Vue.use(TabbarItem)
Vue.use(Col)
Vue.use(Row)
Vue.use(VanImage)

async function test(){
  const res = recommendMusicAPI({limit:20})
  console.log(res)
}
test();

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
