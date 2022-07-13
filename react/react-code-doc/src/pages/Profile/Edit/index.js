import React from 'react'
import NavBar from '@/components/NavBar'
import { List } from 'antd-mobile'
import styles from './index.module.scss'
export default function index() {
  return (
    <div className={styles.root}>
      <NavBar>个人信息</NavBar>
      <div className="wrapper">
        <List className="profile-list">
          <List.Item
            onClick={() => {}}
            extra={
              <span className="avatar-wrapper">
                <img
                  src="http://geek.itheima.net/images/user_head.jpg"
                  alt=""
                />
              </span>
            }
          >
            头像
          </List.Item>
          <List.Item extra={'13711111111'} onClick={() => {}}>
            昵称
          </List.Item>
          <List.Item extra={'未填写'} onClick={() => {}}>
            简介
          </List.Item>
        </List>
      </div>
    </div>
  )
}
