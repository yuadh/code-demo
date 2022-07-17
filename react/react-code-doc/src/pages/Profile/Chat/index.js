import React, { useEffect, useRef } from 'react'
import styles from './index.module.scss'
import Icon from '@/components/Icon'
import NavBar from '@/components/NavBar'
import Input from '@/components/Input'
import { useState } from 'react'
import { getProfileAPI } from '@/store/actions/profile'
import { useDispatch, useSelector } from 'react-redux'
import io from 'socket.io-client'
import { getToken } from '@/utils/storage'
export default function Chat() {
  const [messageList, setMessageList] = useState([
    // 放两条初始消息
    { type: 'robot', text: '亲爱的用户您好，小智同学为您服务。' },
    { type: 'user', text: '你好' },
  ])
  const [msg, setMsg] = useState('')
  const photo = useSelector((state) => state.profile.user.photo)
  console.log(photo)
  const dispatch = useDispatch()
  const onKeyUp = (e) => {
    if (e.keyCode !== 13) return
    if (!msg) return
    // 加入到数组
    setMessageList([...messageList, { type: 'user', text: msg }])
    // 发送至服务端
    clientRef.current.emit('message', {
      msg,
      timestamp: Date.now(),
    })
    // 清空消息
    setMsg('')
  }
  const clientRef = useRef(null)
  const listRef = useRef(null)
  useEffect(() => {
    dispatch(getProfileAPI())
    const client = io('http://geek.itheima.net', {
      query: {
        token: getToken().token,
      },
      transports: ['websocket'],
    })
    clientRef.current = client
    client.on('connect', function () {
      setMessageList((messageList) => {
        return [
          ...messageList,
          { type: 'robot', text: '我是小智障,有什么要问的呢？' },
        ]
      })
    })
    client.on('message', function (dat) {
      setMessageList((messageList) => {
        return [
          ...messageList,
          {
            type: 'robot',
            text: dat.msg,
          },
        ]
      })
    })
    return () => {
      client.close()
    }
  }, [dispatch])
  useEffect(() => {
    // 滚动条处理
    listRef.current.scrollTop =
      listRef.current.scrollHeight - listRef.current.offsetHeight
  }, [messageList])
  return (
    <div className={styles.root}>
      {/* 顶部导航栏 */}
      <NavBar className="fixed-header">小智同学</NavBar>

      {/* 聊天记录列表 */}
      <div className="chat-list" ref={listRef}>
        {messageList.map((item, index) => {
          if (item.type === 'robot') {
            return (
              <div key={index} className="chat-item">
                <Icon type="iconbtn_xiaozhitongxue" />
                <div className="message">{item.text}</div>
              </div>
            )
          } else {
            return (
              <div key={index} className="chat-item user">
                <img src={photo} alt="" />
                <div className="message">{item.text}</div>
              </div>
            )
          }
        })}
      </div>

      {/* 底部消息输入框 */}
      <div className="input-footer">
        <Input
          className="no-border"
          placeholder="请描述您的问题"
          value={msg}
          onChange={(e) => {
            return setMsg(e.target.value)
          }}
          onKeyUp={onKeyUp}
        />
        <Icon type="iconbianji" />
      </div>
    </div>
  )
}
