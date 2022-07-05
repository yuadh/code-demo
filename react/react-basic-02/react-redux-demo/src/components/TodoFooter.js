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
  return (
    <footer className="footer">
      <span className="todo-count">
        <strong>{count}</strong> item left
      </span>
      <ul className="filters">
        <li
          onClick={() => {
            change('all')
          }}
        >
          <a className={dat === 'all' ? 'selected' : ''} href="#/">
            All
          </a>
        </li>
        <li
          onClick={() => {
            change('active')
          }}
        >
          <a className={dat === 'active' ? 'selected' : ''} href="#/active">
            Active
          </a>
        </li>
        <li
          onClick={() => {
            change('completed')
          }}
        >
          <a
            className={dat === 'completed' ? 'selected' : ''}
            href="#/completed"
          >
            Completed
          </a>
        </li>
      </ul>
      <button className="clear-completed">Clear completed</button>
    </footer>
  )
}

export default TodoFooter
