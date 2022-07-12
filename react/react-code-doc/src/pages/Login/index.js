import React, { useState } from 'react'
import NavBar from '@/components/NavBar'
import styles from './index.module.scss'
import Input from '@/components/Input'
import { useFormik } from 'formik'
import * as Yup from 'yup'
import classNames from 'classnames'
import { loginAPI, sendCodeAPI } from '@/store/actions/login'
import { useDispatch } from 'react-redux'
import { Toast } from 'antd-mobile'
export default function Login() {
  const [times, setTimes] = useState(0)
  const dispatch = useDispatch()
  const onExtraClick = async () => {
    // console.log('233')
    // sendCodeAPI
    if (!/^1[3-9]\d{9}$/.test(mobile)) {
      formik.setTouched({ mobile: true })
      return
    }

    await dispatch(sendCodeAPI(mobile))
    Toast.show({
      icon: 'success',
      content: '验证码发送成功',
      duration: 1000,
    })
    setTimes(3)
    const timeId = setInterval(() => {
      // 闭包下times拿到的数据为函数外部记录的0值
      setTimes((times) => {
        if (times === 1) {
          clearInterval(timeId)
        }
        return times - 1
      })
    }, 1000)
  }
  // 校验方式一 ： validate
  // const validate = (values) => {
  //   const errors = {}
  //   if (!values.mobile) {
  //     errors.mobile = '手机号不能为空'
  //   }
  //   if (!values.code) {
  //     errors.code = '验证码不能为空'
  //   }
  //   return errors
  // }
  const formik = useFormik({
    initialValues: {
      mobile: '15507081172',
      code: '',
    },
    // validate,
    validationSchema: Yup.object({
      mobile: Yup.string()
        .required('手机号不能为空')
        .matches(/^1[3-9]\d{9}$/, '手机号格式错误'),
      code: Yup.string()
        .required('验证码不能为空')
        .matches(/^\d{6}$/, '验证码格式错误'),
    }),
    onSubmit: (values) => {
      dispatch(loginAPI(values))
      Toast.show({
        icon: 'success',
        content: '登录成功',
        duration: 1000,
      })
    },
  })
  const {
    values: { mobile, code },
    handleChange,
    handleSubmit,
    isValid,
  } = formik
  return (
    <div className={styles.root}>
      <NavBar>登录</NavBar>
      <div className="content">
        {/* 标题 */}
        <h3>短信登录</h3>
        <form onSubmit={handleSubmit}>
          {/* 手机号输入框 */}
          <div className="input-item">
            <Input
              name="mobile"
              placeholder="请输入手机号"
              autoComplete="off"
              value={mobile}
              onBlur={formik.handleBlur}
              onChange={handleChange}
            />
            {formik.touched.mobile && formik.errors.mobile ? (
              <div className="validate">{formik.errors.mobile}</div>
            ) : null}
          </div>

          {/* 短信验证码输入框 */}
          <div className="input-item">
            <Input
              name="code"
              onBlur={formik.handleBlur}
              placeholder="清输入验证码"
              maxLength={6}
              autoComplete="off"
              extra={times === 0 ? '获取验证码' : times + 's后获取'}
              onExtraClick={onExtraClick}
              value={code}
              onChange={handleChange}
            />
            {formik.touched.code && formik.errors.code ? (
              <div className="validate">{formik.errors.code}</div>
            ) : null}
          </div>

          {/* 登录按钮 */}
          <button
            type="submit"
            className={classNames('login-btn ', { disabled: !isValid })}
            disabled={!isValid}
          >
            登录
          </button>
        </form>
      </div>
    </div>
  )
}
