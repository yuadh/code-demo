import React, { Component } from 'react'
import { Layout, Menu, Popconfirm } from 'antd'
import { Link, Route, Switch } from 'react-router-dom'
import ArticleList from 'pages/ArticleList'
import ArticlePublish from 'pages/ArticlePublish'
import Main from 'pages/Main'
import { removeToken } from 'utils/storage'
import { getUserInfo } from 'api/user.js'
import {
  LogoutOutlined,
  WindowsFilled,
  SnippetsFilled,
  HighlightFilled,
} from '@ant-design/icons'
import style from './index.module.less'
const { Header, Content, Sider } = Layout
export default class Home extends Component {
  state = {
    profile: {},
  }
  render() {
    return (
      <div className={style.home}>
        <Layout>
          <Header className="header">
            <div className="logo" />
            <div className="userInfo">
              <span className="userName">{this.state.profile.name}</span>
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
                defaultSelectedKeys={[this.props.location.pathname]}
                style={{ height: '100%', borderRight: 0 }}
              >
                <Menu.Item icon={<WindowsFilled />} key="/home">
                  <Link to="/home">数据概览</Link>
                </Menu.Item>
                <Menu.Item icon={<SnippetsFilled />} key="/home/article">
                  <Link to="/home/article">内容管理</Link>
                </Menu.Item>
                <Menu.Item icon={<HighlightFilled />} key="/home/publish">
                  <Link to="/home/publish">发布文章</Link>
                </Menu.Item>
              </Menu>
            </Sider>
            <Layout className="layoutContent" style={{ padding: '20px' }}>
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
  async getUser() {
    const res = await getUserInfo()
    this.setState({
      profile: res.data,
    })
  }
  componentDidMount() {
    this.getUser()
  }
  logout = () => {
    console.log('退出测试')
    removeToken()
    this.props.history.push('/login')
  }
}
