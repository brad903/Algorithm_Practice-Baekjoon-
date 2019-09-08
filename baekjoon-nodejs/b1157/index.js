var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().toUpperCase();
var arr = new Array(26).fill(0);

for (let i = 0; i < input.length; i++) {
    arr[input.charCodeAt(i) - 'A'.charCodeAt(0)]++;
}

var result = '?'
var count = 0;
for (let i = 0; i < arr.length; i++) {
    if(arr[i] > count) {
        result = String.fromCharCode(i + 65);
        count = arr[i];
    }else if(arr[i] == count) {
        result = '?';
    }
}

console.log(result);