import React from 'react'
import Icon from '@/components/Icon'
import './index.scss'
export default function Home() {
  return (
    <div>
      home
      <Icon
        type={'iconbtn_like_sel'}
        className="big"
        onClick={() => {
          alert('test')
        }}
      ></Icon>
      123
    </div>
  )
}
