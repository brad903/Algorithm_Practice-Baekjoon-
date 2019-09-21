var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split(' ').map(Number);

const A = input[0];
const B = input[1];
const V = input[2];

const answer = Math.ceil((V - A) / (A - B)) + 1;
console.log(answer);