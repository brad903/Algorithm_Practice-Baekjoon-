var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');
const N = Number(input.shift());
const direction = [[0, 1], [0, -1], [1, 0], [-1, 0]];

for (let ts = 0; ts < N; ts++) {
    const data = input.shift().split(' ').map(Number);
    const map = initMap(data, input);
    const visit = initVisit(data);

    let count = 0;
    for (let row = 0; row < data[1]; row++) {
        for (let col = 0; col < data[0]; col++) {
            if (visit[row][col] || !map[row][col]) continue;

            let queue = [[row, col]];
            visit[row][col] = true;
            while (queue.length) {
                [y, x] = queue.shift();
                for (let index = 0; index < direction.length; index++) {
                    let newRow = y + direction[index][0];
                    let newCol = x + direction[index][1];
                    if (isReachable(newRow, newCol, data) && !visit[newRow][newCol] && map[newRow][newCol] == 1) {
                        visit[newRow][newCol] = true;
                        queue.push([newRow, newCol]);
                    }
                }
            }
            count++;
        }
    }

    console.log(count);
}

function isReachable(row, col, data) {
    return row >= 0 && row < data[1] && col >= 0 && col < data[0];
}

function initMap(data, input) {
    let arr = [];
    for (let i = 0; i < data[1]; i++) {
        arr.push(new Array(data[0]).fill(0));
    }
    for (let i = 0; i < data[2]; i++) {
        const point = input.shift().split(' ').map(Number);
        arr[point[1]][point[0]] = 1;
    }
    return arr;
}

function initVisit(data) {
    let arr = [];
    for (let i = 0; i < data[1]; i++) {
        arr.push(new Array(data[0]).fill(false));
    }
    return arr;
}