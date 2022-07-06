import { useSelector } from 'react-redux'
import TodoItem from './TodoItem'
const TodoMain = () => {
  const list = useSelector(({ todos, filter }) => {
    if (filter === 'all') {
      return todos
    } else if (filter === 'active') {
      return todos.filter((item) => !item.done)
    } else if (filter === 'completed') {
      return todos.filter((item) => item.done)
    }
  })
  // const stage = useSelector((state) => state.filter)
  // let listFilter = []
  // if (stage === 'all') {
  //   listFilter = list
  // } else if (stage === 'active') {
  //   listFilter = list.filter((item) => !item.done)
  // } else if (stage === 'completed') {
  //   listFilter = list.filter((item) => item.done)
  // }
  return (
    <section className="main">
      <input id="toggle-all" className="toggle-all" type="checkbox" />
      <label htmlFor="toggle-all">Mark all as complete</label>
      <ul className="todo-list">
        {list.map((item) => (
          <TodoItem key={item.id} item={item}></TodoItem>
        ))}
      </ul>
    </section>
  )
}

export default TodoMain
