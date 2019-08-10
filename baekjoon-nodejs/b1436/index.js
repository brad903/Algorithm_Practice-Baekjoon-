var fs = require('fs');
var input = fs.readFileSync('./stdin').toString();

const N = parseInt(input);

let count = 0;
for(let i = 666; ; i++) {
    let text = i.toString();
    if(text.includes(666)) count++;
    if(count === N) {
        console.log(i);
        break;
    }
}