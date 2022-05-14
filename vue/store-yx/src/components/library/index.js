
// 扩展vue原有的功能：全局组件、自定义指令... 称为插件
// vue2插件写法要素：导出一个对象,有 install 函数，默认传入Vue构造函数，Vue基础上扩展
// vue3插件写法要输：导出一个对象,有 install 函数，默认传入App应用实例，app基础上扩展
import defaultImg  from "@/assets/images/200.png"

export default{
  install(app){
    defineDirective(app)
  }
}


const defineDirective = (app)=>{
  app.directive('lazy',{
    mounted(el,binding){
      const observe = new IntersectionObserver(([{isIntersecting}])=>{
        if(isIntersecting){
          observe.unobserve(el)
          el.onerror = ()=>{
            el.src = defaultImg
          }
          console.log('图片懒加载DD')
          el.src = binding.value
        }
      },{threshold:0})
      observe.observe(el)
    }
  })
} 