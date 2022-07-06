import { changeStage } from '../store/actions/filter'
import { useDispatch, useSelector } from 'react-redux'
const TodoFooter = () => {
  const dispatch = useDispatch()
  const dat = useSelector((state) => state.filter)
  const list = useSelector((state) => state.todos)
  const count = list.filter((item) => !item.done).length
  console.log(count)
  const change = (stage) => {
    dispatch(changeStage(stage))
    console.log(dat)
  }
  const arr = ['all', 'active', 'completed']
  return (
    <footer className="footer">
      <span className="todo-count">
        <strong>{count}</strong> item left
      </span>
      <ul className="filters">
        {arr.map((item, index) => (
          <li
            key={index}
            onClick={() => {
              change(item)
            }}
          >
            <a className={dat === item ? 'selected' : ''} href="/#">
              {item}
            </a>
          </li>
        ))}
      </ul>
      <button className="clear-completed">Clear completed</button>
    </footer>
  )
}

export default TodoFooter
