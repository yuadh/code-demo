const customName = document.getElementById('customname'); //自定义名字
const randomize = document.querySelector('.randomize'); //按钮
const story = document.querySelector('.story'); //文本框
function randomValueFromArray(array) {
    return array[Math.floor(Math.random() * array.length)];
} //随机返回数组中一个元素

const storyText = "今天气温 34 摄氏度，:inserta:出去遛弯。当走到:insertb:门前时，突然就:insertc:。人们都惊呆了，李雷全程目睹但并没有慌，因为:inserta:是一个 130 公斤的胖子，天气又辣么热。";
const insertX = [
    "怪兽威利",
    "大老爹",
    "圣诞老人"
];
const insertY = [
    "肯德基",
    "迪士尼乐园",
    "白宫"
]
const insertZ = [
    "自燃了",
    "在人行道化成了一坨泥",
    "变成一条鼻涕虫爬走了"
];


randomize.addEventListener('click', result);

function result() {
    var newStory = storyText,
        xItem, yItem, zItem;
    let name;
    xItem = randomValueFromArray(insertX);
    yItem = randomValueFromArray(insertY);
    zItem = randomValueFromArray(insertZ);
    if (customName.value !== '') {
        name = customName.value;
        newStory = storyText.replace("李雷", name);
    }
    if (document.getElementById("american").checked) {
        let weight = Math.round(300);
        let temperature = Math.round(94);
    }
    newStory = newStory.replace(":inserta:", xItem);
    newStory = newStory.replace(":inserta:", xItem);
    newStory = newStory.replace(":insertb:", yItem);
    newStory = newStory.replace(":insertc:", zItem);
    console.log(newStory);
    story.textContent = newStory;
    story.style.visibility = 'visible';
}