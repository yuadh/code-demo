import Vue from 'vue'
import dayjs from 'dayjs'


// 加载中文语言包
import 'dayjs/locale/zh-cn'

import relativeTime from 'dayjs/plugin/relativeTime'


dayjs.extend(relativeTime)

dayjs.locale('zh-cn')


Vue.filter('relativeTime', value => {
    return dayjs().to(dayjs(value))
})