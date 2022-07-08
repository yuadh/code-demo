import React from 'react'
import ReactDOM from 'react-dom/client'
import 'antd/dist/antd.min.css'
import './index.less'
import App from './App'
import zhCN from 'antd/lib/locale/zh_CN'
import 'moment/locale/zh-cn'
import { ConfigProvider } from 'antd'
import moment from 'moment'
moment.locale('en')
const root = ReactDOM.createRoot(document.getElementById('root'))
root.render(
  <ConfigProvider locale={zhCN}>
    <App />
  </ConfigProvider>
)
