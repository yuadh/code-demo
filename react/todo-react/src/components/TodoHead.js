import React, { Component } from 'react'

export default class todoHead extends Component {
  state = {
    name: '',
  }
  render() {
    this.tRef = React.createRef()
    return (
      <header className="header">
        <h1>todos</h1>
        <input
          ref={this.tRef}
          className="new-todo"
          placeholder="What needs to be done?"
          autoFocus
          onKeyUp={this.addTask}
          value={this.state.name}
          onChange={(e) => this.setState({ name: e.target.value })}
        />
      </header>
    )
  }
  addTask = (e) => {
    if (e.keyCode !== 13) {
      return
    }
    if (!this.state.name.trim()) {
      return alert('null')
    }
    this.props.todoAddTask(this.state.name)
    this.setState({
      name: '',
    })
  }
}
