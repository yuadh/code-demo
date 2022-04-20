<template>
  <ul class="todo-list">
    <!-- completed: 完成的类名 -->
    <li :class="{completed:obj.todoIsDone}" v-for="obj in todoList" :key="obj.id">
      <div class="view">
          <!-- //v-model 接受复选框时如果不是数组接受 是checked属性 -->
        <input class="toggle" type="checkbox" v-model="obj.todoIsDone" />
        <label>{{obj.name}}</label>
        <!-- 删除任务 -->
        <button class="destroy" @click="rmTodoItem(obj)"></button>
      </div>
    </li>
  </ul>
  
</template>

<script>
export default {
    //添加任务功能
    props: ['todoList'],
    methods: {
        //移除功能
        rmTodoItem(obj){
            console.log("dianji")
            this.$emit('rmTodoItem', obj.id)
        }
    }
}
</script>