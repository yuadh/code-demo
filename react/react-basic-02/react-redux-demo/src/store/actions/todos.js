// 提供todos相关的action
import axios from 'axios'

// 获取任务列表 异步
export const getList = () => {
  return async (dispatch) => {
    const res = await axios.get('http://localhost:8888/todos')
    dispatch({
      type: 'GET_LIST',
      payload: res.data,
    })
  }
}

// 添加任务
export const addTodo = (name) => {
  return async (dispatch) => {
    const res = await axios.post('http://localhost:8888/todos', {
      name,
      done: false,
    })
    dispatch({
      type: 'ADD_TODO',
      payload: res.data,
    })
  }
}
