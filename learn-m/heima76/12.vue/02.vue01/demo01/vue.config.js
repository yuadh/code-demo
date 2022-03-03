const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
    transpileDependencies: true,
    devServer: {
        port: 3000,
        open: true
    },
    lintOnSave: false, //关闭js代码检查工具 eslint
})