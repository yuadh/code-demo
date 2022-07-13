import React, { Suspense } from 'react'
import Icon from '@/components/Icon'
import styles from './index.module.scss'
import classNames from 'classnames'
import { Switch, Route, useHistory, useLocation } from 'react-router-dom'
const Main = React.lazy(() => import('@/pages/Main'))
const Profile = React.lazy(() => import('@/pages/Profile'))
const Video = React.lazy(() => import('@/pages/Video'))
const QA = React.lazy(() => import('@/pages/QA'))
export default function Home() {
  const location = useLocation()
  const history = useHistory()
  const tabBar = [
    {
      title: '首页',
      icon: 'iconbtn_home',
      path: '/home',
    },
    {
      title: '问答',
      icon: 'iconbtn_qa',
      path: '/home/qa',
    },
    {
      title: '视频',
      icon: 'iconbtn_video',
      path: '/home/video',
    },
    {
      title: '我的',
      icon: 'iconbtn_mine',
      path: '/home/profile',
    },
  ]
  return (
    <div className={styles.root}>
      {/* 区域一：点击按钮切换显示内容的区域 */}
      <div className="tab-content">
        <Suspense fallback={<div>ej loading</div>}>
          <Switch>
            <Route path="/home" exact component={Main}></Route>
            <Route path="/home/qa" component={QA}></Route>
            <Route path="/home/video" component={Video}></Route>
            <Route path="/home/profile" component={Profile}></Route>
          </Switch>
        </Suspense>
      </div>
      {/* 区域二：按钮区域，会使用固定定位显示在页面底部 */}
      <div className="tabbar">
        {tabBar.map((item) => {
          return (
            <div
              key={item.title}
              className={classNames('tabbar-item', {
                'tabbar-item-active': item.path === location.pathname,
              })}
              onClick={() => history.push(item.path)}
            >
              <Icon
                type={
                  location.pathname === item.path
                    ? item.icon + '_sel'
                    : item.icon
                }
              ></Icon>
              <span>{item.title}</span>
            </div>
          )
        })}
        {/* <div className="tabbar-item tabbar-item-active">
          <Icon type="iconbtn_home_sel" />
          <span>首页</span>
        </div>
        <div className="tabbar-item">
          <Icon type="iconbtn_qa" />
          <span>问答</span>
        </div>
        <div className="tabbar-item">
          <Icon type="iconbtn_video" />
          <span>视频</span>
        </div>
        <div className="tabbar-item">
          <Icon type="iconbtn_mine" />
          <span>我的</span>
        </div> */}
      </div>
    </div>
  )
}
