const fs = require('fs')
const path = require('path')
const http = require('http')

const server = http.createServer()

//时钟web案例
server.on('request', function(req, res) {
    // url: /clock/index.html   /clock/index.css    /clock/index.js
    const url = req.url
        //优化路径问题
    var fpath = ''
    if (url == '/') {
        fpath = path.join(__dirname, '/clock/index.html');
        console.log(fpath);
    } else {
        fpath = path.join(__dirname, '/clock', url);
    }
    fs.readFile(fpath, 'utf-8', function(err, dat) {
        // res.setHeader('Content-Type', 'text/html;charest=utf-8')
        if (err) {
            res.end('404')
        }
        res.end(dat)
    })
})

server.listen(80, function() {
    console.log('server runing at http://127.0.0.1:8080')
});