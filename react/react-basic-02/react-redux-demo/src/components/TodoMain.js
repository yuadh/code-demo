import { useSelector } from 'react-redux'
import TodoItem from './TodoItem'
const TodoMain = () => {
  const list = useSelector((state) => state.todos)
  const stage = useSelector((state) => state.filter)
  let listFilter = []
  if (stage === 'all') {
    listFilter = list
  } else if (stage === 'active') {
    listFilter = list.filter((item) => !item.done)
  } else if (stage === 'completed') {
    listFilter = list.filter((item) => item.done)
  }
  return (
    <section className="main">
      <input id="toggle-all" className="toggle-all" type="checkbox" />
      <label htmlFor="toggle-all">Mark all as complete</label>
      <ul className="todo-list">
        {listFilter.map((item) => (
          <TodoItem key={item.id} item={item}></TodoItem>
        ))}
      </ul>
    </section>
  )
}

export default TodoMain
