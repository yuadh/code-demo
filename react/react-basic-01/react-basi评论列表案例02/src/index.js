import React from 'react'
import ReactDOM from 'react-dom'

/* 
  评论列表案例

  comments: [
    { id: 1, name: 'jack', content: '沙发！！！' },
    { id: 2, name: 'rose', content: '板凳~' },
    { id: 3, name: 'tom', content: '楼主好人' }
  ]
*/

import './index.css'

class App extends React.Component {
  // constructor() {
  //   super()
  // }

  state = {
    list: [
      { id: 1, name: 'y', comment: '代码练习太少了' },
      { id: 2, name: 'd', comment: '外包接单没法接' },
      { id: 3, name: 'h', comment: '写起东西无从下手' },
      { id: 4, name: 's', comment: '资源较少，没有经验' },
    ],
    user: '',
    content: '',
  }
  render() {
    return (
      <div className="app">
        <div>
          <input
            onChange={this.handleChange}
            className="user"
            name="user"
            type="text"
            placeholder="请输入评论人"
            value={this.state.user}
          />
          <br />
          <textarea
            onChange={this.handleChange}
            className="content"
            name="content"
            cols="30"
            rows="10"
            value={this.state.content}
            placeholder="请输入评论内容"
          />
          <br />
          <button onClick={this.sendComment}>发表评论</button>
          <button onClick={this.clearComment}>清空评论</button>
        </div>
        {this.state.list.length !== 0 ? (
          <ul>
            {this.state.list.map((item) => {
              return (
                <li key={item.id}>
                  <h3>评论人：{item.name}</h3>
                  <p>评论内容：{item.comment}</p>
                  <button
                    onClick={() => {
                      this.deleteComment(item.id)
                    }}
                  >
                    删除评论
                  </button>
                </li>
              )
            })}
          </ul>
        ) : (
          <div className="no-comment">暂无评论，快去评论吧~</div>
        )}
      </div>
    )
  }
  handleChange = (e) => {
    const { name, value } = e.target
    this.setState({
      [name]: value,
    })
  }
  clearComment = () => {
    this.setState({
      list: [],
    })
  }
  deleteComment = (id) => {
    const newList = this.state.list.filter((item) => item.id !== id)
    this.setState({
      list: newList,
    })
  }
  sendComment = () => {
    if (this.state.user.length === 0 || this.state.content.length === 0) {
      alert('信息不完整')
      return
    }
    const add = {
      id: Date.now(),
      name: this.state.user,
      comment: this.state.content,
    }
    this.setState({
      list: [add, ...this.state.list],
      user: '',
      content: '',
    })
  }
}

// 渲染组件
ReactDOM.render(<App />, document.getElementById('root'))
