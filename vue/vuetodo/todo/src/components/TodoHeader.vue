<template>
  <header class="header">
    <h1>todos</h1>
    <input id="toggle-all" class="toggle-all" type="checkbox" v-model="selectAll">
    <label for="toggle-all"></label>
    <input
      @keydown.enter.down="addTodo()"
      class="new-todo"
      placeholder="输入任务名称-回车确认"
      autofocus
      v-model="todoItem"
    />
  </header>
</template>

<script>
export default {
    //组件之间通信，添加任务
    props: ['todoList']
    ,
    data () {
        return {
            todoItem:"",
            ABtnSta:false,
        }
    },
    methods: {
        addTodo(){
            //非空判断
            if(this.todoItem.trim().length===0){
                alert('任务不能为空');
                return;
            }
            console.log(this.todoItem)
            this.$emit('addTodoItem', this.todoItem)
            this.todoItem=""//情况操作
        },
    },
    computed: {
        selectAll:{
            set(checkSta){//这里获取到了v-model的值变化
                this.todoList.forEach(obj=>{
                    obj.todoIsDone=checkSta
                })
            },
            //双向绑定 小框影响大框
            get(){
                return this.todoList.length !== 0 && this.todoList.every(obj=>{
                    return obj.todoIsDone === true
                })
            }
        }
    }
}
</script>