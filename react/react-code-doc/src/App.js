import React, { Suspense } from 'react'
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Redirect,
} from 'react-router-dom'
import './App.scss'
// 路由组件的按需加载(懒加载)
const Login = React.lazy(() => import('@/pages/Login'))
const Home = React.lazy(() => import('@/pages/Home'))
const Edit = React.lazy(() => import('@/pages/Profile/Edit'))
export default function App() {
  return (
    <Router>
      <div className="app">
        <Suspense fallback={<div>loading...</div>}>
          <Switch>
            <Redirect exact from="/" to="/home"></Redirect>
            <Route path="/home" component={Home}></Route>
            <Route path="/login" component={Login}></Route>
            <Route path="/profile/edit" component={Edit}></Route>
          </Switch>
        </Suspense>
      </div>
    </Router>
  )
}
