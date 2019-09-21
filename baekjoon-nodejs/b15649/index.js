var fs = require('fs');
const input = fs.readFileSync('./stdin').toString().split(' ');

const N = Number(input[0]);
const R = Number(input[1]);
var arr = Array.from(Array(N + 1).keys()).slice(1);
var answers = [];

permutation(N, R, 0);
answers = sort(answers);
Array(answers)[0].forEach(element => {
    console.log(element);
})

function sort(answers) {
    return answers.sort((a, b) => {
        return String(a).localeCompare(String(b));
    });
}

function swap(a, b) {
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

function store() {
    let temp = '';
    for (let i = 0; i < R; i++) {
        temp = temp.concat(arr[i] + ' ');
    }
    answers.push(temp.trim());
}

function permutation(n, r, cur) {
    if (r === cur) {
        store();
        return;
    }

    for (let i = cur; i < n; i++) {
        swap(i, cur)
        permutation(n, r, cur + 1);
        swap(i, cur);
    }
}