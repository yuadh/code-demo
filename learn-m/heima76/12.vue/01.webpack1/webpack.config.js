const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
module.exports = {
    entry: './mysrc/index.js',
    output: {
        path: path.resolve(__dirname, 'mydist'),
        filename: 'main.js',
    },
    plugins: [new HtmlWebpackPlugin({ template: './public/index.html' })],
    module: {
        rules: [{
                test: /\.css$/i, //一个对象 一个规则
                use: ["style-loader", "css-loader"],
                //从右到左开始加载，所以顺序不能颠倒
                //css-loader : 将css代码打包进 js 文件在宏
                //style-loader : 将js中的css代码加入到DOM文中
            }, {
                test: /\.less$/i,
                use: ["style-loader", "css-loader", "less-loader"]
            },
            {
                test: /\.(gif|png|jpg|jpeg)$/,
                type: 'asset', //webpack会将以上资源做静态资源打包
                //如果识别的是 asset 模式
                //大于 8kb 的文件会直接输入到 dist 文件下,小于 8kb 的文件会转成base64打包进js
            }, {
                test: /\.(eot|svg|ttf|woff|woff2)$/,
                type: 'asset/resource',
                generator: {
                    filename: 'static/[name].[hash:6][ext]'
                }
            },
            {
                test: /\.m?js$/,
                exclude: /(node_modules|bower_components)/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-env']
                    }
                }
            }
        ],
    },
};