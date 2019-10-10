var fs = require('fs');
const N = Number(fs.readFileSync('./stdin').toString());

let count = 0;
for (let i = 1; i <= N; i++) {
    if (isHansu(i)) count++;
}
console.log(count);

function isHansu(num) {
    if (num < 10) return true;
    const numChars = String(num);
    const d = numChars.charAt(1) - numChars.charAt(0);

    for (let n = 0; n < numChars.length; n++) {
        let nthNum = Number(numChars.charAt(0)) + (n * d);
        if (numChars.charAt(n) != nthNum) return false;
    }
    return true;
}