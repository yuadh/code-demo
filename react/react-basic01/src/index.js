import ReactDOM from 'react-dom'

const list = [
  { id: 1, name: 'y', value: 111 },
  { id: 2, name: 'd', value: 222 },
  { id: 3, name: 'h', value: 333 },
]

const element = (
  <>
    <ul>
      {list.map((item) => (
        <li key={item.id}>
          <h3>The Name = {item.name}</h3>
          <p>the value = {item.value}</p>
        </li>
      ))}
    </ul>
  </>
)
ReactDOM.render(element, document.getElementById('root'))
