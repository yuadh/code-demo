import React, { useEffect, useState } from 'react'
import NavBar from '@/components/NavBar'
import { List, DatePicker, Toast, Popup } from 'antd-mobile'
import styles from './index.module.scss'
import classNames from 'classnames'
import { getProfileDetailsAPI } from '@/store/actions/profile'
import { useDispatch, useSelector } from 'react-redux'
import EditInput from './components/EditInput'
export default function Edit() {
  const [dateVisible, setDateVisible] = useState(false)
  const [drawVisible, setDrawVisible] = useState({
    visible: false,
    type: '',
  })
  const onClose = () => {
    setDrawVisible({
      visible: false,
      type: '',
    })
  }
  const dispatch = useDispatch()
  const profile = useSelector((state) => state.profile.profile)
  console.log(profile)
  useEffect(() => {
    dispatch(getProfileDetailsAPI())
  }, [dispatch])
  return (
    <div className={styles.root}>
      <div className="content">
        <NavBar>个人信息</NavBar>
        <div className="wrapper">
          <List className="profile-list">
            <List.Item
              arrow={true}
              onClick={() => {}}
              extra={
                <span className="avatar-wrapper">
                  <img src={profile.photo} alt="" />
                </span>
              }
            >
              头像
            </List.Item>
            <List.Item
              arrow={true}
              extra={profile.name}
              onClick={() => {
                setDrawVisible({
                  visible: true,
                  type: 'name',
                })
              }}
            >
              昵称
            </List.Item>
            <List.Item
              arrow={true}
              extra={profile.intro || '未填写'}
              className={classNames('intro', profile.intro ? 'normal' : '')}
              onClick={() => {
                setDrawVisible({
                  visible: true,
                  type: 'intro',
                })
              }}
            >
              简介
            </List.Item>
          </List>

          <List className="profile-list">
            <List.Item arrow={true} extra={'男'} onClick={() => {}}>
              性别
            </List.Item>

            <List.Item
              onClick={() => {
                setDateVisible(true)
              }}
              arrow={true}
              extra={<div>{profile.birthday}</div>}
            >
              生日
            </List.Item>
          </List>
        </div>

        <div className="logout">
          <button className="btn">退出登录</button>
        </div>
      </div>
      <Popup
        visible={drawVisible.visible}
        onMaskClick={() => {
          setDrawVisible(false)
        }}
        position="right"
        bodyStyle={{ width: '100vw' }}
      >
        <div>
          <EditInput onClose={onClose} type={drawVisible.type} />
        </div>
      </Popup>
      <DatePicker
        title="选择生日"
        value={new Date(profile.birthday)}
        visible={dateVisible}
        onClose={() => {
          setDateVisible(false)
        }}
        max={new Date()}
        min={new Date('1900-01-01')}
        onChange={() => {}}
        onConfirm={(val) => {
          Toast.show(val.toDateString())
        }}
      />
    </div>
  )
}
