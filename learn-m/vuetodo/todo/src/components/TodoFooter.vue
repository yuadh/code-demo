<template>
  <footer class="footer">
    <span class="todo-count">剩余<strong>数量值</strong>{{todoItemCount}}</span>
    <ul class="filters" @click="itemClassShow">
      <!-- 点击框赛选显示 组件之间的通信 -->
      <li>
        <a :class="{'selected':showSta==='all'}" href="javascript:;" @click="showSta='all'">全部</a>
      </li>
      <li>
        <a :class="{'selected':showSta==='no'}" href="javascript:;" @click="showSta='no'">未完成</a>
      </li>
      <li>
        <a :class="{'selected':showSta==='yes'}" href="javascript:;" @click="showSta='yes'" >已完成</a>
      </li>
    </ul>
    <!-- 清楚已完成任务 -->
    <input v-mode="otest">
    <button class="clear-completed" @click="delDoneItems" >{{test.title}}</button>
  </footer>
</template>

<script>
export default {
    data () {
      return {
        showSta:"all"
      }
    },
    //底部统计功能
    props:["todoList","test"],
    computed: {
      todoItemCount(){
        //赛选出未完成数量
        return this.todoList.length;
      }
    },
    methods: {
      itemClassShow(){
        this.$emit('itemClassShow', this.showSta)
      },
      delDoneItems(){
        this.test = {
          title:'101',
          id:2
        }
        this.$emit('delDoneItems')
      }
    },
    computed:{
      otest:{
        set(){
          return test={
            title:"test",
            id:3
          }
        },
        get(){
           return this.test={
            title:"test",
            id:3
          }
        }
      }
    }

}
</script>