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
          console.log('是否有token测试', getToken())
          if (hasToken()) {
            console.log('有token调整home')
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
