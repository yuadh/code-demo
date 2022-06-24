import ReactDOM from 'react-dom'
import { Component } from 'react'

class App extends Component {
  constructor() {
    super()
    this.state = {
      list: ['y', 'd', 'h'],
      count: 100,
    }
  }
  render() {
    return (
      <div>
        <h1>XXX</h1>
        <ul>
          {this.state.list.map((item, index) => (
            <li key={index}>{item}</li>
          ))}
        </ul>
        <div>{this.state.count}</div>
        <button onClick={this.handleClick}>点击事件</button>
        <button onClick={this.handleAdd}>点击添加</button>
      </div>
    )
  }
  handleClick = () => {
    this.setState({
      count: this.state.count + 1,
    })
  }
  handleAdd = () => {
    this.setState({
      list: [...this.state.list, 's', 'w'],
    })
  }
}
ReactDOM.render(<App />, document.getElementById('root'))
