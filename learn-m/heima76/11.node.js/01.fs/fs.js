//使用 node.js

const fs = require('fs');

fs.readFile('./t.txt', 'utf-8', function(err, dataStr) {
    if (err) {
        return console.log('error错误信息' + err.message);
        //错误信息 第一个参数如果成功返回值为 null  失败返回值为一个对象
    }
    console.log(dataStr);
});
fs.writeFile('./z.txt', 'tzl', 'utf-8', function(err) {
    if (err) {
        return console.log('error错误信息' + err.message);
        //错误信息 第一个参数如果成功返回值为 null  失败返回值为一个对象
    }
    console.log('success');
});