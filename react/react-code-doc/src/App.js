import React, { Suspense } from 'react'
import { Router, Switch, Route, Redirect } from 'react-router-dom'
import AuthRoute from './components/AuthRoute'
import history from './utils/history'
import './App.scss'
// 路由组件的按需加载(懒加载)
const Login = React.lazy(() => import('@/pages/Login'))
const Home = React.lazy(() => import('@/pages/Home'))
const Edit = React.lazy(() => import('@/pages/Profile/Edit'))
const Chat = React.lazy(() => import('@/pages/Profile/Chat'))
export default function App() {
  return (
    <Router history={history}>
      <div className="app">
        <Suspense fallback={<div>loading...</div>}>
          <Switch>
            <Redirect exact from="/" to="/home"></Redirect>
            <Route path="/home" component={Home}></Route>
            <Route path="/login" component={Login}></Route>
            <AuthRoute path="/profile/edit" component={Edit}></AuthRoute>
            <AuthRoute path="/profile/chat" component={Chat}></AuthRoute>
          </Switch>
        </Suspense>
      </div>
    </Router>
  )
}
