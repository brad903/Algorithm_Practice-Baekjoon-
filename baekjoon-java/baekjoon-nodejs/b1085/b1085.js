var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split(' ');

console.log(Math.min(input[0], input[1], input[2] - input[0], input[3] - input[1]));