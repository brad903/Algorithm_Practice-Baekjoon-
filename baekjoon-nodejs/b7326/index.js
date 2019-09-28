var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

var N = Number(input.shift());
for (let index = 0; index < N; index++) {
    const nums = input.shift().split(' ').map(Number);
    const x = nums[0];
    const y = nums[1];

    let a, b;
    a = Math.floor(x / 2);
    if (y == x) {
        if (x % 2 == 0) b = 0;
        if (x % 2 == 1) b = 1;
    } else if (y == x - 2) {
        if (x % 2 == 0) b = -2;
        if (x % 2 == 1) b = -1;
    }

    if (a === undefined || b === undefined) {
        console.log('No Number');
    } else {
        console.log(4 * a + b);
    }
}