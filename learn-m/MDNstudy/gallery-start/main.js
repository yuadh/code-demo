const displayedImage = document.querySelector('.displayed-img'); //图片显示框
const thumbBar = document.querySelector('.thumb-bar'); //缩略图

const btn = document.querySelector('button'); //变暗按钮
const overlay = document.querySelector('.overlay'); //覆盖层

/* 添加图片循环 */

for (let i = 1; i < 6; i++) {
    let picsrc = "./images/pic" + i + ".jpg";
    const newImage = document.createElement('img');
    newImage.setAttribute('src', picsrc);
    newImage.addEventListener("click", function() {
        displayedImage.setAttribute("src", picsrc);
    });
    thumbBar.appendChild(newImage);
}
/* 编写 变暗/变量 按钮功能 */
btn.addEventListener("click", function() {
    console.log(btn.innerText);
    if (btn.getAttribute("class") === "dark") {
        btn.setAttribute("class", "light");
        btn.innerText = "变亮";
        overlay.setAttribute("style", "background-color:rgba(0, 0, 0, 0.5)");
    } else if (btn.getAttribute("class") === "light") {
        btn.setAttribute("class", "dark");
        btn.innerText = "变暗";
        overlay.setAttribute("style", "background-color:rgba(0, 0, 0, 0)");
    }
});

///
// const displayedImage = document.querySelector('.displayed-img');
// const thumbBar = document.querySelector('.thumb-bar');

// const btn = document.querySelector('button');
// const overlay = document.querySelector('.overlay');

// /* Looping through images */

// for (let i = 1; i <= 5; i++) {
//     const newImage = document.createElement('img');
//     newImage.setAttribute('src', 'images/pic' + i + '.jpg');
//     thumbBar.appendChild(newImage);
//     newImage.onclick = function(e) {
//         displayedImage.src = e.target.src;
//     }
// }

// /* Wiring up the Darken/Lighten button */

// btn.onclick = function() {
//     const btnClass = btn.getAttribute('class');
//     if (btnClass === 'dark') {
//         btn.setAttribute('class', 'light');
//         btn.textContent = '变亮';
//         overlay.style.backgroundColor = 'rgba(0,0,0,0.5)';
//     } else {
//         btn.setAttribute('class', 'dark');
//         btn.textContent = '变暗';
//         overlay.style.backgroundColor = 'rgba(0,0,0,0)';
//     }
// }