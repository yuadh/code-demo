import React, { Component } from 'react'

export default class todoFoot extends Component {
  render() {
    const { list, type } = this.props
    if (list.length === 0) {
      return
    }
    const isShow = list.some((item) => item.isDone)
    return (
      <footer className="footer">
        <span className="todo-count">
          <strong>
            {this.props.list.filter((item) => !item.isDone).length}
          </strong>{' '}
          item left
        </span>
        <ul className="filters">
          <li>
            <a
              onClick={() => {
                this.handleClick('all')
              }}
              className={type === 'all' ? 'selected' : ''}
              href="#/"
            >
              All
            </a>
          </li>
          <li>
            <a
              onClick={() => {
                this.handleClick('active')
              }}
              className={type === 'active' ? 'selected' : ''}
              href="#/active"
            >
              Active
            </a>
          </li>
          <li>
            <a
              onClick={() => {
                this.handleClick('completed')
              }}
              className={type === 'completed' ? 'selected' : ''}
              href="#/completed"
            >
              Completed
            </a>
          </li>
        </ul>
        {isShow && (
          <button onClick={this.clearTasks} className="clear-completed">
            Clear completed
          </button>
        )}
      </footer>
    )
  }
  clearTasks = () => {
    this.props.todoClearTasks()
  }
  handleClick = (type) => {
    this.props.typeChange(type)
  }
}
