var fs = require('fs')
var input = fs.readFileSync('./stdin').toString().split('\n')

const data = input.shift().split(' ').map(Number);
const rowLength = data[0];
const colLength = data[1];
const direction = [[0, 1], [0, -1], [1, 0], [-1, 0]];

const map = initMap(input, rowLength);
var memo = initMemo(rowLength, colLength);

const result = dfs(rowLength - 1, colLength - 1);

console.log(result);

function dfs(row, col) {
    if (memo[row][col] != -1) return memo[row][col];
    if (row == 0 && col == 0) return 1;

    memo[row][col] = 0;
    for (let index = 0; index < direction.length; index++) {
        let nextRow = row + direction[index][0];
        let nextCol = col + direction[index][1];

        if (isValidIndex(nextRow, nextCol) && isValidPoint(map[row][col], map[nextRow][nextCol])) {
            memo[row][col] += dfs(nextRow, nextCol);
        }
    }

    return memo[row][col];
}

function isValidPoint(previous, next) {
    return next > previous;
}

function isValidIndex(row, col) {
    return row >= 0 && row < rowLength && col >= 0 && col < colLength;
}

function initMap(input, rowLength) {
    let arr = [];
    for (let row = 0; row < rowLength; row++) {
        arr.push(input.shift().split(' ').map(Number));
    }
    return arr;
}

function initMemo(rowLength, colLength) {
    let arr = [];
    for (let row = 0; row < rowLength; row++) {
        let temp = [];
        for (let col = 0; col < colLength; col++) {
            temp.push(-1);
        }
        arr.push(temp);
    }
    return arr;
}