import { Router, Switch, Route, Redirect } from 'react-router-dom'
import Home from './pages/Home'
import Login from './pages/Login'
import AuthRouter from 'AuthRouter'
import history from 'utils/history.js'
import './App.less'
function App() {
  return (
    <Router history={history}>
      <div className="App">
        <Switch>
          <Redirect exact path="/" to="/home"></Redirect>
          {/* <Route path="/home" component={Home}></Route> */}
          <Route path="/login" component={Login}></Route>
          <AuthRouter path="/home" component={Home}></AuthRouter>
          <Route component={123}></Route>
        </Switch>
      </div>
    </Router>
  )
}

export default App
