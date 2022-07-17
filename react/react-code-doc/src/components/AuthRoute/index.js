import { hasToken } from '@/utils/storage'
import React from 'react'
import { Redirect, Route, useLocation } from 'react-router-dom'

export default function AuthRoute({ component: Component, ...rest }) {
  const location = useLocation()
  return (
    <Route
      {...rest}
      render={() => {
        if (hasToken()) {
          console.log('路由守卫有token')
          return <Component></Component>
        } else {
          console.log('路由守卫无token')
          return (
            <Redirect
              to={{
                pathname: '/login',
                state: {
                  from: location.pathname,
                },
              }}
            ></Redirect>
          )
        }
      }}
    ></Route>
  )
}
