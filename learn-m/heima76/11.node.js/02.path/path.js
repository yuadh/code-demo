//正则表达式 \s 表示空白字符 \S 表示非空白字符 * 表示任意次

const fs = require('fs');
const path = require('path');

const regStyle = /<style>[\s\S]*<\/style>/
const regScript = /<script>[\s\S]*<\/script>/

fs.readFile(path.join(__dirname, 'index.html'), 'utf-8', function(err, htmlStr) {
        if (err) {
            return console.log(err.message);
        }
        resolveCSS(htmlStr);
        resolveJS(htmlStr);
        resolveHTML(htmlStr);
    })
    //写入css文件
function resolveCSS(htmlStr) {
    const tc = regStyle.exec(htmlStr)
    const dat = tc[0].replace('<style>', '').replace('</style>', '');
    fs.writeFile(path.join(__dirname, '/clock/index.css'), dat, function(err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('css文件写入成功');
    })
}
//写入js文件
function resolveJS(htmlStr) {
    const tc = regScript.exec(htmlStr)
    const dat = tc[0].replace('<script>', '').replace('</script>', '');
    fs.writeFile(path.join(__dirname, '/clock/index.js'), dat, function(err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('js文件写入成功');
    })
}

function resolveHTML(htmlStr) {
    const newHtml = htmlStr.replace(regStyle, '<link rel="stylesheet" href="./index.css">')
        .replace(regScript, '<script src="./index.js"></script>');
    fs.writeFile(path.join(__dirname, '/clock/index.html'), newHtml, function(err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('html文件写入成功');
    })
}