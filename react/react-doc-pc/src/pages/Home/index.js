import React, { Component } from 'react'
import { Layout, Menu, Popconfirm } from 'antd'
import { Link, Route, Switch } from 'react-router-dom'
import ArticleList from 'pages/ArticleList'
import ArticlePublish from 'pages/ArticlePublish'
import Main from 'pages/Main'
import { removeToken } from 'utils/storage'
import {
  LogoutOutlined,
  WindowsFilled,
  SnippetsFilled,
  HighlightFilled,
} from '@ant-design/icons'
import style from './index.module.less'
const { Header, Content, Sider } = Layout

export default class Home extends Component {
  render() {
    return (
      <div className={style.home}>
        <Layout>
          <Header className="header">
            <div className="logo" />
            <div className="userInfo">
              <span className="userName">黑马先锋</span>
              <span className="userLogout">
                <Popconfirm
                  title="是否确认退出"
                  okText="确定"
                  cancelText="取消"
                  placement="bottomLeft"
                  onConfirm={this.logout}
                >
                  <LogoutOutlined /> 退出
                </Popconfirm>
              </span>
            </div>
          </Header>
          <Layout>
            <Sider width={200}>
              <Menu
                mode="inline"
                theme="dark"
                // defaultOpenKeys={['sub1']}
                defaultSelectedKeys={['1']}
                style={{ height: '100%', borderRight: 0 }}
              >
                <Menu.Item icon={<WindowsFilled />} key="1">
                  <Link to="/home">数据概览</Link>
                </Menu.Item>
                <Menu.Item icon={<SnippetsFilled />} key="2">
                  <Link to="/home/article">内容管理</Link>
                </Menu.Item>
                <Menu.Item icon={<HighlightFilled />} key="3">
                  <Link to="/home/publish">发布文章</Link>
                </Menu.Item>
              </Menu>
            </Sider>
            <Layout style={{ padding: '24px' }}>
              <Content className="site-layout-background">
                <Switch>
                  <Route exact path="/home" component={Main}></Route>
                  <Route path="/home/article" component={ArticleList}></Route>
                  <Route
                    path="/home/publish"
                    component={ArticlePublish}
                  ></Route>
                </Switch>
              </Content>
            </Layout>
          </Layout>
        </Layout>
      </div>
    )
  }
  logout = () => {
    console.log('退出测试')
    removeToken()
    this.props.history.push('/login')
  }
}
