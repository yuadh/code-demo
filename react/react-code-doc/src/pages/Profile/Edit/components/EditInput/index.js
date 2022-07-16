import Input from '@/components/Input'
import NavBar from '@/components/NavBar'
import Textarea from '@/components/Textarea'
import React, { useEffect, useState } from 'react'
import { useSelector } from 'react-redux'
import styles from './index.module.scss'

export default function EditInput({ onClose, type, onCommit }) {
  console.log(type)
  const defaultValue = useSelector((state) => {
    return state.profile.profile[type]
  })
  useEffect(() => {
    return console.log('卸载')
  }, [])
  const [value, setValue] = useState(defaultValue || '')
  return (
    <div className={styles.root}>
      <NavBar
        extra={
          <span
            className="commit-btn"
            onClick={() => {
              onCommit(type, value)
            }}
          >
            提交
          </span>
        }
        onLeftClick={onClose}
      >
        编辑{type === 'name' ? '昵称' : '简介'}
      </NavBar>
      <div className="content-box">
        <h3>{type === 'name' ? '昵称' : '简介'}</h3>

        {type === 'name' ? (
          <Input
            className="input-wrap"
            value={value}
            onChange={(e) => {
              setValue(e.target.value)
            }}
          ></Input>
        ) : (
          <Textarea
            maxLength={200}
            placeholder="测试输入框"
            value={value}
            onChange={(e) => {
              setValue(e.target.value)
            }}
          ></Textarea>
        )}
      </div>
    </div>
  )
}
