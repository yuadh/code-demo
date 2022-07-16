import classNames from 'classnames'
import React, { useEffect, useRef } from 'react'
import styles from './index.module.scss'
export default function Input({
  extra,
  autoFucos,
  onExtraClick,
  className,
  ...rest
}) {
  const inputRef = useRef(null)
  useEffect(() => {
    if (autoFucos) {
      inputRef.current.focus()
    }
  }, [autoFucos])
  return (
    <div className={styles.root}>
      <input
        ref={inputRef}
        className={classNames('input', className)}
        {...rest}
      />
      {extra && (
        <div className="extra" onClick={onExtraClick}>
          {extra}
        </div>
      )}
    </div>
  )
}
