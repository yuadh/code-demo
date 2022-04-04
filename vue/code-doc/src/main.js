import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import {
    Button,
    NavBar,
    Form,
    Field,
    CellGroup,
    Toast,
    CountDown,
    Tabbar,
    TabbarItem,
    Grid,
    GridItem,
    Cell,
    Icon,
    Image as VanImage,
    Dialog,
    Popup,
    Picker,
    DatetimePicker

} from 'vant';
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
Vue.use(Tabbar)
Vue.use(TabbarItem)
Vue.use(Grid)
Vue.use(GridItem)
Vue.use(Cell)
Vue.use(Icon)
Vue.use(VanImage)
Vue.use(Dialog)
Vue.use(Popup)
Vue.use(Picker)
Vue.use(DatetimePicker)
new Vue({
    router,
    store,
    render: h => h(App)
}).$mount('#app')