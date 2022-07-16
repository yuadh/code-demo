import React from 'react'
import styles from './index.module.scss'
export default function EditList({ config, type, onClose }) {
  const list = config[type]

  console.log(list)
  return (
    <div className={styles.root}>
      {/* <div className="list-item">男</div>
      <div className="list-item">女</div> */}
      {list.map((item) => {
        return (
          <div key={item.title} className="list-item" onClick={item.onClick}>
            {item.title}
          </div>
        )
      })}
      <div className="list-item" onClick={onClose}>
        取消
      </div>
    </div>
  )
}
