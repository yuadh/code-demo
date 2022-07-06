import { useEffect, useRef, useState } from 'react'
import { useDispatch } from 'react-redux'
import { delTodo, togTodo, chTodoName } from '../store/actions/todos'
export default function TodoItem({ item }) {
  const dispatch = useDispatch()
  const [current, setCurrent] = useState('')
  const del = (id) => {
    console.log(id)
    dispatch(delTodo(id))
  }
  const tog = (id, done) => {
    dispatch(togTodo(id, done))
  }
  const inputRef = useRef(null)
  const changeName = (id) => {
    setCurrent(id)
    console.log('doueble')
  }
  useEffect(() => {
    inputRef.current.focus()
  }, [current])

  const chNa = (e, id) => {
    if (e.keyCode === 27) {
      setCurrent('')
    }
    if (e.keyCode === 13) {
      dispatch(chTodoName(current, e.target.value))
      setCurrent('')
    }
  }
  return (
    <li
      className={[
        item.done ? 'completed' : '',
        current === item.id ? 'editing' : '',
      ].join(' ')}
    >
      <div className="view">
        <input
          className="toggle"
          type="checkbox"
          checked={item.done}
          onChange={(e) => {
            tog(item.id, e.target.checked)
          }}
        />
        <label
          onDoubleClick={() => {
            changeName(item.id)
          }}
        >
          {item.name}
        </label>
        <button
          className="destroy"
          onClick={() => {
            del(item.id)
          }}
        />
      </div>
      <input
        className="edit"
        ref={inputRef}
        defaultValue={item.name}
        onBlur={() => {
          setCurrent('')
        }}
        onKeyUp={(e) => {
          chNa(e, item.id)
        }}
      />
    </li>
  )
}
