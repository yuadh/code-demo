import React, { useEffect, useRef, useState } from 'react'
import NavBar from '@/components/NavBar'
import { List, DatePicker, Toast, Popup, Dialog } from 'antd-mobile'
import styles from './index.module.scss'
import classNames from 'classnames'
import {
  getProfileDetailsAPI,
  updatePhoto,
  updateProfile,
} from '@/store/actions/profile'
import { useDispatch, useSelector } from 'react-redux'
import EditInput from './components/EditInput'
import EditList from './components/EditList'
import dayjs from 'dayjs'
import { logout } from '@/store/actions/login'
import { useHistory } from 'react-router-dom'
export default function Edit() {
  const history = useHistory()
  const [dateVisible, setDateVisible] = useState(false)
  const [drawVisible, setDrawVisible] = useState({
    visible: false,
    type: '',
  })
  const [drawBVisible, setDrawBVisible] = useState({
    visible: false,
    type: '',
  })
  const inputRef = useRef(null)
  const onFileChange = (e) => {
    const file = e.target.files[0]
    const fd = new FormData()
    fd.append('photo', file)
    dispatch(updatePhoto(fd))
    Toast.show({
      icon: 'success',
      content: '修改成功',
      duration: 1000,
    })
    onClose()
  }
  const onClose = () => {
    setDrawVisible({
      visible: false,
      type: '',
    })
    setDrawBVisible({
      visible: false,
      type: '',
    })
  }
  const config = {
    avatar: [
      {
        title: '拍照',
        onClick: () => {
          console.log('拍照')
        },
      },
      {
        title: '本地选择',
        onClick: () => {
          inputRef.current.click()
          console.log('本地选择')
        },
      },
    ],
    gender: [
      {
        title: '男',
        onClick: () => {
          onCommit('gender', 0)
        },
      },
      {
        title: '女',
        onClick: () => {
          onCommit('gender', 1)
        },
      },
    ],
  }
  const dispatch = useDispatch()
  const profile = useSelector((state) => state.profile.profile)
  console.log(profile)
  const onCommit = async (type, value) => {
    await dispatch(
      updateProfile({
        [type]: value,
      })
    )
    Toast.show({
      icon: 'success',
      content: '修改成功',
      duration: 1000,
    })
    onClose()
  }
  useEffect(() => {
    dispatch(getProfileDetailsAPI())
  }, [dispatch])
  return (
    <div className={styles.root}>
      <input
        type="file"
        style={{ display: 'none' }}
        hidden
        ref={inputRef}
        onChange={onFileChange}
      />
      <div className="content">
        <NavBar>个人信息</NavBar>
        <div className="wrapper">
          <List className="profile-list">
            <List.Item
              arrow={true}
              onClick={() => {
                setDrawBVisible({
                  visible: true,
                  type: 'avatar',
                })
              }}
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
            <List.Item
              arrow={true}
              extra={profile.gender === 0 ? '男' : '女'}
              onClick={() => {
                setDrawBVisible({
                  visible: true,
                  type: 'gender',
                })
              }}
            >
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
          <button
            className="btn"
            onClick={async () => {
              const result = await Dialog.confirm({
                content: '确认退出',
              })
              if (result) {
                // Toast.show({ content: '点击了确认', position: 'bottom' })
                dispatch(logout())
                history.push('/login')
                Toast.show({
                  icon: 'success',
                  content: '退出成功',
                  duration: 1000,
                })
              } else {
                // Toast.show({ content: '点击了取消', position: 'bottom' })
              }
            }}
          >
            退出登录
          </button>
        </div>
      </div>
      {/* 修改昵称和简介的右侧弹窗 */}
      <Popup
        visible={drawVisible.visible}
        onMaskClick={() => {
          setDrawVisible(false)
        }}
        position="right"
        bodyStyle={{ width: '100vw' }}
      >
        <div>
          {drawVisible.visible && (
            <EditInput
              onCommit={onCommit}
              onClose={onClose}
              type={drawVisible.type}
            />
          )}
        </div>
      </Popup>
      {/* 修改头像和性别的底部弹窗 */}
      <Popup
        onMaskClick={() => {
          setDrawBVisible(false)
        }}
        visible={drawBVisible.visible}
        bodyStyle={{
          height: '26vh',
          borderTopLeftRadius: '12px',
          borderTopRightRadius: '12px',
        }}
      >
        <div>
          {drawBVisible.visible && (
            <EditList
              config={config}
              type={drawBVisible.type}
              onClose={onClose}
            ></EditList>
          )}
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
          onCommit('birthday', dayjs(val).format('YYYY-MM-DD'))
        }}
      />
    </div>
  )
}
