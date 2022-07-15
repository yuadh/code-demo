import React from 'react'
import styles from './index.module.scss'
import Icon from '../Icon'
import { useHistory } from 'react-router-dom'

function NavBar({ children, extra, onLeftClick }) {
  const history = useHistory()
  const back = () => {
    if (onLeftClick) {
      onLeftClick()
    } else {
      history.go(-1)
    }
  }
  const rightHandle = () => {
    console.log('提交函数')
  }
  return (
    <div className={styles.root}>
      <div className="left" onClick={back}>
        <Icon type="iconfanhui" />
      </div>
      <div className="title">{children}</div>
      <div className="right" onClick={rightHandle}>
        {extra}
      </div>
    </div>
  )
}
// 解决方式1 ： 使用 useRouter
// export default withRouter(NavBar)

// 解决方式2 ： 使用useHistory
export default NavBar
