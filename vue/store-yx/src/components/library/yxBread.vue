
<script>
import { h } from 'vue'
// 面板屑组件
export default {
  render(){
    const items  = this.$slots.default()
    const dymanicItems = []
    items.forEach((item,i)=>{
      dymanicItems.push(item)
      if(i<(items.length-1)){
        dymanicItems.push(h('i',{class:'iconfont iconfont-angle-right'}))
      }
    })
    return h('div',{class:'yxBread'},dymanicItems)
  }
}
</script>

<style lang="less" scoped>
  
</style>