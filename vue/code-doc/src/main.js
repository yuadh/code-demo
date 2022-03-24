import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import { Button, NavBar, Form, Field, CellGroup, Toast,CountDown  } from 'vant';
import 'amfe-flexible'
import "@/styles/index.less"
Vue.config.productionTip = false
Vue.use(Button)
Vue.use(NavBar)
Vue.use(Form)
Vue.use(Field)
Vue.use(CellGroup)
Vue.use(Toast)
Vue.use(CountDown)
new Vue({
    router,
    store,
    render: h => h(App)
}).$mount('#app')