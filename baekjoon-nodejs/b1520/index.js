var fs = require('fs')
var input = fs.readFileSync('./stdin').toString().split('\n')

const data = input.shift().split(' ').map(Number);
const rowLength = data[0];
const colLength = data[1];
const direction = [[0, 1], [0, -1], [1, 0], [-1, 0]];

const map = initMap(input, rowLength);
var visit = initVisit(rowLength, colLength);
var count = 0;

dfs(0, 0);

console.log(count);

function dfs(row, col) {
    if(row == rowLength - 1 && col == colLength - 1) count++;

    visit[row][col] = true;
    for (let index = 0; index < direction.length; index++) {
        let nextRow = row + direction[index][0];
        let nextCol = col + direction[index][1];

        if (isValidIndex(nextRow, nextCol) && isValidPoint(map[row][col], map[nextRow][nextCol]) && !visit[nextRow][nextCol]) {
            dfs(nextRow, nextCol);
        }
    }
    visit[row][col] = false;
}

function isValidPoint(previous, next) {
    return next < previous;
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

function initVisit(rowLength, colLength) {
    let arr = [];
    for (let row = 0; row < rowLength; row++) {
        let temp = [];
        for (let col = 0; col < colLength; col++) {
            temp.push(false);
        }
        arr.push(temp);
    }
    return arr;
}