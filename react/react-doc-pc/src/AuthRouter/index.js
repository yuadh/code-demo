import React, { Component } from 'react'
import { Redirect, Route } from 'react-router-dom'
import { getToken, hasToken } from 'utils/storage'

export default class AuthRouter extends Component {
  render() {
    const { component: Component, ...rest } = this.props
    // console.log(Component)
    return (
      <Route
        {...rest}
        render={(data) => {
          // render 接收到的 date数据是路由提供的router对象
          console.log('是否有token测试', getToken())
          if (hasToken()) {
            console.log('有token调整home', data)
            return <Component {...data} />
          }
          return (
            <Redirect
              to={{
                pathname: '/login',
                state: { from: data.location.pathname },
              }}
            />
          )
        }}
      ></Route>
    )
  }
}
