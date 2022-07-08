import React, { Component } from 'react'
import {
  Breadcrumb,
  Card,
  Button,
  Form,
  Radio,
  Select,
  DatePicker,
  Space,
  Table,
  Tag,
} from 'antd'
import { EditOutlined, DeleteOutlined } from '@ant-design/icons'
import { Link } from 'react-router-dom'
import { ArticleStatus } from 'api/constant'
import { getChannelAPI } from 'api/channel'
import { getArticlesAPI } from 'api/article'
import defaultImg from 'assets/images/defaultImage.png'
const { Option } = Select
const { RangePicker } = DatePicker
export default class ArticleList extends Component {
  state = {
    channels: [],
    articles: [],
  }
  columns = [
    {
      title: '封面',
      render: (data) => {
        if (data.cover.type === 0) {
          return (
            <img
              src={defaultImg}
              alt=""
              style={{ width: 200, height: 150, objectFit: 'cover' }}
            ></img>
          )
        }
        return (
          <img
            src={data.cover.images[0]}
            alt=""
            style={{ width: 200, height: 150, objectFit: 'cover' }}
          />
        )
      },
    },
    {
      title: '标题',
      dataIndex: 'title',
      width: 220,
    },
    {
      title: '状态',
      dataIndex: 'status',
      render: (status) => {
        console.log(status)
        const obj = ArticleStatus.find((item) => item.id === status)
        return <Tag color={obj.color}>{obj.name}</Tag>
      },
    },
    {
      title: '发布时间',
      dataIndex: 'pubdate',
    },
    {
      title: '阅读数',
      dataIndex: 'read_count',
    },
    {
      title: '评论数',
      dataIndex: 'comment_count',
    },
    {
      title: '点赞数',
      dataIndex: 'like_count',
    },
    {
      title: '操作',
      render: () => {
        return (
          <Space size="middle">
            <Button type="primary" shape="circle" icon={<EditOutlined />} />
            <Button
              type="primary"
              danger
              shape="circle"
              icon={<DeleteOutlined />}
            />
          </Space>
        )
      },
    },
    // {
    //   title: 'Action',
    //   key: 'action',
    //   render: (_, record) => (
    //     <Space size="middle">
    //       <a>Invite {record.name}</a>
    //       <a>Delete</a>
    //     </Space>
    //   ),
    // },
  ]
  render() {
    const { total_count, results } = this.state.articles
    return (
      <>
        <Card
          title={
            <Breadcrumb>
              <Breadcrumb.Item>
                <Link to="/home">首页</Link>
              </Breadcrumb.Item>
              <Breadcrumb.Item>
                <Link to="/home/article">文章列表</Link>
              </Breadcrumb.Item>
            </Breadcrumb>
          }
        >
          <Form
            initialValues={{
              status: -1,
            }}
            onFinish={this.onFinish}
          >
            <Form.Item name="status" label="状态">
              <Radio.Group>
                {ArticleStatus.map((item) => {
                  return (
                    <Radio key={item.id} value={item.id}>
                      {item.name}
                    </Radio>
                  )
                })}
              </Radio.Group>
            </Form.Item>
            <Form.Item name="channel_id" label="频道">
              <Select placeholder="请输入文章频道" style={{ width: 250 }}>
                {this.state.channels.map((item) => {
                  return (
                    <Option value={item.id} key={item.id}>
                      {item.name}
                    </Option>
                  )
                })}
              </Select>
            </Form.Item>
            <Form.Item name="date" label="日期">
              <RangePicker />
            </Form.Item>
            <Form.Item>
              <Button type="primary" htmlType="submit">
                提交
              </Button>
            </Form.Item>
          </Form>
        </Card>

        <Card title={`当前共查询到${total_count}条数据`}>
          <Table columns={this.columns} dataSource={results} rowKey="id" />
        </Card>
      </>
    )
  }
  onFinish = (values) => {
    console.log('Success:', values)
  }
  getChannel = async () => {
    const res = await getChannelAPI()
    console.log(res)
    this.setState({
      channels: res.data.channels,
    })
  }
  getArticles = async () => {
    const res = await getArticlesAPI()
    console.log(res)
    this.setState({
      articles: res.data,
    })
  }
  componentDidMount() {
    this.getChannel()
    this.getArticles()
  }
}
