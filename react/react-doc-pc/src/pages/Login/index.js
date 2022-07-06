import React, { Component } from 'react'
import { Card, Button, Checkbox, Form, Input, message } from 'antd'
import logo from 'assets/images/logo.png'
import './index.less'
import { userLoginApi } from 'api/user.js'
import { setToken } from 'utils/storage'
export default class index extends Component {
  state = {
    loading: false,
  }
  render() {
    return (
      <div className="login">
        <Card className="login-container">
          <img className="login-logo" src={logo} alt=""></img>
          <Form
            size="large"
            onFinish={this.onFinish}
            initialValues={{
              mobile: '15507081172',
              code: '246810',
              agree: true,
            }}
          >
            <Form.Item
              name="mobile"
              validateTrigger={['onChange', 'onBlur']}
              rules={[
                {
                  pattern: /^1[3-9]\d{9}$/,
                  message: '手机号格式错误',
                  validateTrigger: 'onBlur',
                },
                {
                  required: true,
                  message: '手机号不能为空',
                  validateTrigger: 'onChange',
                },
              ]}
            >
              <Input size="large" placeholder="请输入手机号" />
            </Form.Item>

            <Form.Item
              name="code"
              validateTrigger={['onChange', 'onBlur']}
              rules={[
                {
                  required: true,
                  message: '验证码不能为空',
                  validateTrigger: 'onChange',
                },
                {
                  pattern: /^\d{6}$/,
                  message: '验证码格式错误',
                  validateTrigger: 'onBlur',
                },
              ]}
            >
              <Input size="large" placeholder="请输入验证码" />
            </Form.Item>

            <Form.Item
              name="agree"
              valuePropName="checked"
              rules={[
                {
                  validator: (rule, value) =>
                    value
                      ? Promise.resolve()
                      : Promise.reject(new Error('请勾选协议')),
                },
              ]}
            >
              <Checkbox>我已阅读并同意协议</Checkbox>
            </Form.Item>

            <Form.Item>
              <Button
                type="primary"
                htmlType="submit"
                size="large"
                block
                loading={this.state.loading}
              >
                登录
              </Button>
            </Form.Item>
          </Form>
        </Card>
      </div>
    )
  }
  onFinish = async ({ mobile, code }) => {
    this.setState({
      loading: true,
    })
    try {
      const res = await userLoginApi(mobile, code)
      console.log(res)
      setToken(res.data.token)
      message.success('登录成功', 1, () => {
        this.props.history.push('/home')
      })
    } catch (err) {
      console.log(err)
      message.warning(err.response.data.message, 1, () => {
        this.setState({
          loading: false,
        })
      })
    }
  }
}
