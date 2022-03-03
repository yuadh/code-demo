<template>
  <section class="todoapp">
    <!-- 除了驼峰, 还可以使用-转换链接 -->
    <TodoHeader :todoList="showMainList" @addTodoItem="addTodoItem"></TodoHeader>
    <TodoMain :todoList="showMainList" @rmTodoItem="rmTodoItem"></TodoMain>
    <TodoFooter :todoList="showMainList"  :test="test" @itemClassShow="itemClassShow" @delDoneItems="delDoneItems"></TodoFooter>
  </section>
</template>

<script>
// 1.0 样式引入
import "./style/base.css"
import "./style/index.css"
    
import TodoHeader from "./components/TodoHeader";
import TodoMain from "./components/TodoMain";
import TodoFooter from "./components/TodoFooter";


export default {
  components: {
    TodoHeader,
    TodoMain,
    TodoFooter,
  },
  data () {
    return {
      todoList:JSON.parse(localStorage.getItem('todoList'))||[],
      showSta:"all",
      test:{
        title:'100',
        id:1
      },

    }
  },
  methods: {
    addTodoItem(todoItem){
      //添加任务方法
      //注意 更新数组，和限制空任务输入
      //获取最后一个
      let id = this.todoList.length === 0?100:this.todoList[this.todoList.length-1].id+1;
      console.log(id);
      this.todoList.push({
        id:id,
        name:todoItem,
        todoIsDone:false
      })
      console.log(todoItem)
    },
    rmTodoItem(deId){
      console.log(deId)
      let index = this.todoList.findIndex(obj=>obj.id===deId)
      this.todoList.splice(index,1)
    },
    itemClassShow(showSta){
      this.showSta=showSta
    },
    delDoneItems(){
      console.log("删除全部测试")
      this.$set(this.todoList=this.todoList.filter(obj=>{
        return obj.todoIsDone===false
      }))
    },
    //实现本地存储的方法
  },
  computed: {
    showMainList(){
      //根据显示状态 更新数组 底部统计也需要返回
      if(this.showSta==='yes'){
          return this.todoList.filter(obj=>{
            return obj.todoIsDone===true
          })
      }else if(this.showSta==='no'){
          return this.todoList.filter(obj=>{
            return obj.todoIsDone===false
          })
      }else {
        return this.todoList
      }
    }
  },
  // watch: {
  //   //监听器，将数据存储到本地存储
  //   todoList:{
  //     handler(newTodoList){
  //       localStorage.setItem('todoList',JSON.stringify(newTodoList))
  //     },
  //     deep:true,
  //     immediate:true
  //   }
  // }
};
</script>