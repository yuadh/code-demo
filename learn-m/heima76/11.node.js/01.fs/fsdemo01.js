const fs = require('fs');


fs.readFile('./成绩.txt', 'utf-8', function(err, dataStr) {
    if (err) {
        return console.log(err.message);
    }
    const arrOld = dataStr.split(" ");
    const arrNew = [];
    arrOld.forEach(item => {
        arrNew.push(item.replace("=", ":"));
    })
    const newStr = arrNew.join("\r\n");
    fs.writeFile('./xx.txt', newStr, function(err) {
        if (err) {
            return console.log(err.message);
        }
        console.log("success");
    })
})