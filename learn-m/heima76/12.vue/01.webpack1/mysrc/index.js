import $ from 'jquery'
import './css/main.css'
import './less/main.less'
$("ul>li:odd").css('color', 'red')
$("ul>li:even").css('color', 'yellow')
import imgURL from './asset/1.gif'
let myimg = document.createElement("img")
myimg.src = imgURL
document.body.appendChild(myimg)

//添加字体图标
import './asset/download/font_meqrhr9epn/iconfont.css'
let myicon = document.createElement('span')
myicon.className = 'iconfont icon-daka'
document.body.appendChild(myicon)

const fn = (() => {
    console.log('兼容低版本js')
})
fn()