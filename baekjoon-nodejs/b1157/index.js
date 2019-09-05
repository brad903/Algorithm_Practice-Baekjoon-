var fs = require('fs');
var input = fs.readFileSync('./stdin').toString();

var map = new Map();
for(let i = 0; i < input.length; i++) {
    let key = input[i].toUpperCase();
    if(map.has(key)) map.set(key, map.get(key) + 1);
    else map.set(key, 1);
}

var arr = new Array();
for (const key of map.keys()) {
    arr.push([key, map.get(key)]);
}
arr.sort((a, b) => b[1] - a[1]);

if(arr.length == 0) console.log("");
if(arr.length == 1) console.log(arr[0][0]);

if(arr[0][1] == arr[1][1]) console.log('?');
else console.log(arr[0][0]);