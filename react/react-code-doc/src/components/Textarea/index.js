import classNames from 'classnames'
import React, { useEffect, useRef, useState } from 'react'
import styles from './index.module.scss'
export default function Textarea({ maxLength, className, onChange, ...rest }) {
  const [value, setValue] = useState(rest.value || '')
  const inputRef = useRef(null)
  const onChangeHandle = (e) => {
    setValue(e.target.value)
    onChange && onChange(e)
  }
  useEffect(() => {
    inputRef.current.focus()
    inputRef.current.setSelectionRange(-1, -1)
  }, [])
  return (
    <div className={styles.root}>
      <textarea
        ref={inputRef}
        className={classNames('textarea', className)}
        {...rest}
        maxLength={maxLength}
        value={value}
        onChange={(e) => {
          onChangeHandle(e)
        }}
      />
      <div className="count">
        {value.length}/{maxLength}
      </div>
    </div>
  )
}
