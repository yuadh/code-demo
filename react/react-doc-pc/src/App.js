import {
  BrowserRouter as Router,
  Switch,
  Route,
  Redirect,
} from 'react-router-dom'
import Home from './pages/Home'
import Login from './pages/Login'
import './App.less'
function App() {
  return (
    <Router>
      <div className="App">
        <Switch>
          <Redirect exact path="/" to="/home"></Redirect>
          <Route path="/home" component={Home}></Route>
          <Route path="/login" component={Login}></Route>
          <Route component={<div>404</div>}></Route>
        </Switch>
      </div>
    </Router>
  )
}

export default App
