import React, { Component } from 'react'
import classnames from 'classnames'
export default class todoMain extends Component {
  state = {
    currentId: '',
    curContent: '',
  }
  constructor() {
    super()
    this.inputRef = React.createRef()
  }
  render() {
    const { list } = this.props
    return (
      <section className="main">
        <input
          id="toggle-all"
          className="toggle-all"
          checked={list.every((item) => item.isDone)}
          type="checkbox"
          onChange={this.selectAll}
        />
        <label htmlFor="toggle-all">Mark all as complete</label>
        <ul className="todo-list">
          {list.map((item) => {
            return (
              <li
                className={classnames({
                  completed: item.isDone,
                  editing: this.state.currentId === item.id,
                })}
                key={item.id}
              >
                <div className="view">
                  <input
                    className="toggle"
                    type="checkbox"
                    checked={item.isDone}
                    onChange={() => {
                      this.togState(item.id)
                    }}
                  />
                  <label
                    onDoubleClick={() => {
                      this.showEdit(item)
                    }}
                  >
                    {item.content}
                  </label>
                  <button
                    className="destroy"
                    onClick={() => {
                      this.delTask(item.id)
                    }}
                  ></button>
                </div>
                <input
                  className="edit"
                  ref={this.inputRef}
                  value={this.state.curContent}
                  onBlur={() => {
                    this.setState({
                      currentId: '',
                    })
                  }}
                  onKeyUp={this.changeCont}
                  onChange={(e) => {
                    this.setState({ curContent: e.target.value })
                  }}
                />
              </li>
            )
          })}
        </ul>
      </section>
    )
  }
  delTask = (id) => {
    this.props.todoDelTask(id)
  }
  togState = (id) => {
    this.props.todoTogState(id)
  }
  showEdit = ({ id, content }) => {
    this.setState({
      currentId: id,
      curContent: content,
    })
  }
  changeCont = (e) => {
    if (e.keyCode === 27) {
      this.setState({
        currentId: '',
        curContent: '',
      })
    }
    if (e.keyCode === 13) {
      this.props.todoChangeCont(this.state.curContent, this.state.currentId)
      this.setState({
        currentId: '',
        curContent: '',
      })
    }
  }
  selectAll = (e) => {
    this.props.checkAll(e.target.checked)
  }
  componentDidUpdate() {
    console.log(this.inputRef)
    this.inputRef.current.focus()
  }
}
