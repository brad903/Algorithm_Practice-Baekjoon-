var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

const N = Number(input.shift());
var blue = 0;
var white = 0;
var map = [];
for (let i = 0; i < N; i++) {
    map.push(input[i].split(' ').map(Number));
}

recursive(0, 0, N);

console.log(white);
console.log(blue);

function recursive(row, col, length) {
    if (length == 1) {
        checkColor(map[row][col]);
        return;
    }

    const half = length / 2;
    if (!checkConsistency(row, col, half)) recursive(row, col, half);
    if (!checkConsistency(row, col + half, half)) recursive(row, col + half, half);
    if (!checkConsistency(row + half, col, half)) recursive(row + half, col, half);
    if (!checkConsistency(row + half, col + half, half)) recursive(row + half, col + half, half);
}

function checkConsistency(row, col, length) {
    const representative = map[row][col];
    for (let i = row; i < row + length; i++) {
        for (let j = col; j < col + length; j++) {
            if (map[i][j] != representative) return false;
        }
    }
    checkColor(representative);
    return true;
}

function checkColor(num) {
    if (num == 0) white++;
    if (num == 1) blue++;
}
