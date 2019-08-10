var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

var N = parseInt(input.shift());
var arr = input.shift().split(' ').map(Number);
arr.unshift(0);

var frontDP = new Array(1001).fill(0);
var backDP = new Array(1001).fill(0);

for(let i = 1; i <= N; i++) {
    frontDP[i] = 1;
    for(let j = 1; j <= i; j++) {
        if(arr[j] < arr[i] && frontDP[i] < frontDP[j] + 1) {
            frontDP[i] = frontDP[j] + 1;
        }
    }    
}

for(let i = N; i >= 1; i--) {
    backDP[i] = 1;
    for(let j = N; j >= i; j--) {
        if(arr[j] < arr[i] && backDP[j] + 1 > backDP[i]) {
            backDP[i] = backDP[j] + 1;
        }
    }    
}

var answer = 0;
for(let i = 0; i <= N; i++) {
    if(answer < frontDP[i] + backDP[i] - 1) answer = frontDP[i] + backDP[i] - 1;
}
console.log(answer);