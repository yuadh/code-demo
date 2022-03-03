import thenFs from 'then-fs'


console.log('a');
thenFs.readFile('./a.txt', 'utf8').then(r1 => {
    console.log('b');
})
setTimeout(() => {
    console.log('c');
}, 0)

console.log('d');