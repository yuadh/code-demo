import { createStore, applyMiddleware } from 'redux'
import thunk from 'redux-thunk'
import { composeWithDevTools } from 'redux-devtools-extension'
import reducer from './reducers'
import { getToken } from '@/utils/storage'

const store = createStore(
  reducer,
  {
    login: getToken(),
  },
  composeWithDevTools(applyMiddleware(thunk))
)

export default store
