var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split(' ').map(Number);

var d = new Array(14 * 14).fill(null).map(() => Array(1 << 14).fill(-1));

const N = input[0];
const M = input[1];

console.log(go(0, 0));

function go(num, state) {
    if (num === N * M && state === 0) return 1;
    if (num > N * M) return 0;

    if(d[num][state] !== -1) return d[num][state];

    let ans;
    if (state & 1) {
        ans = go(num + 1, (state >> 1));
    } else {
        ans = go(num + 1, (state >> 1) | (1 << (M - 1)));
        if ((num % M) != (M - 1) && (state & 2) == 0) {
            ans += go(num + 2, (state >> 2));
        }
    }
    return d[num][state] = ans % 9901;
}

