var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

const metaData = input[0].split(' ');
var N = Number(metaData[0]);
const M = Number(metaData[1]);

var queue = Array.from(Array(N + 1).keys()).slice(1);
var indexs = input[1].split(' ').map(Number);

var costs = 0;
for (let i = 0; i < indexs.length; i++) {
    const target = indexs[i];

    let leftMoveQeueue = Array.from(queue);
    let leftCost = 0;
    while (true) {
        let candidate = leftMoveQeueue.shift();
        if (candidate === target) break;
        leftCost++;
        leftMoveQeueue.unshift(candidate);
        leftMoveQeueue.unshift(leftMoveQeueue.pop());
    }

    let rightMoveQeueue = Array.from(queue);
    let rightCost = 0;
    while (true) {
        let candidate = rightMoveQeueue.shift();
        if (candidate === target) break;
        rightCost++;
        rightMoveQeueue.push(candidate);
    }

    if (leftCost < rightCost) {
        queue = leftMoveQeueue;
        costs += leftCost;
    }
    else {
        queue = rightMoveQeueue;
        costs += rightCost;
    }

}
console.log(costs);

