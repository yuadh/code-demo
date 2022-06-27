import React, { Component } from 'react'
import ReactDOM from 'react-dom'
import './style/index.css'
import './style/base.css'
import TodoMain from './components/TodoMain'
import TodoHead from './components/TodoHead'
import TodoFoot from './components/TodoFoot'
export default class App extends Component {
  state = {
    list: [],
    type: 'all',
  }
  render() {
    const { list, type } = this.state
    let showList = []
    if (type === 'all') {
      showList = list
    } else if (type === 'active') {
      showList = list.filter((item) => !item.isDone)
    } else if (type === 'completed') {
      showList = list.filter((item) => item.isDone)
    }
    return (
      <section className="todoapp">
        <TodoHead todoAddTask={this.todoAddTask} />
        <TodoMain
          list={showList}
          todoDelTask={this.todoDelTask}
          todoTogState={this.todoTogState}
          todoChangeCont={this.todoChangeCont}
          checkAll={this.checkAll}
        />
        <TodoFoot
          list={list}
          type={type}
          todoClearTasks={this.todoClearTasks}
          typeChange={this.typeChange}
        />
      </section>
    )
  }

  todoDelTask = (id) => {
    this.setState({
      list: this.state.list.filter((item) => {
        return item.id !== id
      }),
    })
  }
  todoTogState = (id) => {
    this.setState({
      list: this.state.list.map((item) => {
        //不能直接修改其值，赛选出来后覆盖
        if (item.id === id) {
          return {
            ...item,
            isDone: !item.isDone,
          }
        } else {
          return item
        }
      }),
    })
  }
  todoAddTask = (name) => {
    this.setState({
      list: [
        {
          id: Date.now(),
          isDone: false,
          content: name,
        },
        ...this.state.list,
      ],
    })
  }
  todoChangeCont = (name, id) => {
    this.setState({
      list: this.state.list.map((item) => {
        if (item.id === id) {
          return {
            ...item,
            content: name,
          }
        } else {
          return item
        }
      }),
    })
  }
  todoClearTasks = () => {
    this.setState({
      list: this.state.list.filter((item) => !item.isDone),
    })
  }
  typeChange = (type) => {
    this.setState({
      type,
    })
  }
  checkAll = (checked) => {
    this.setState({
      list: this.state.list.map((item) => {
        return {
          ...item,
          isDone: checked,
        }
      }),
    })
  }
}

ReactDOM.render(<App />, document.getElementById('root'))
