var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');
const N = Number(input.shift());
const arr = input.map(row => row.split(' ').map(Number));
arr.unshift([0, 0]);
var map = Array(5).fill(0).map(() => Array(5).fill(0));

for (let i = 1; i < N; i++) {
    map[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
}

for (let m = 2; m <= N; m++) {
    for (let i = 1; i <= N - m; i++) {
        const j = i + m;
        for (let k = i; k < j; k++) {
            let a = map[i][k] + map[k + 1][j] + (arr[i][0] * arr[k][1] * arr[j][1]);
            console.log(arr[i][0] * arr[k][1] * arr[j][1])
            if (!map[i][j] || map[i][j] > a) map[i][j] = a;
            console.log(map);
        }
    }
}
console.log(map[1][N]);

