var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

var weights = new Array();
var heights = new Array();

for(let i = 1; i <= input[0]; i++) {
    let person = input[i].split(' ');
    weights.push({weight: person[0], order: i - 1});
    heights.push({height: person[1], order: i - 1});
}

heights.sort(function(a, b){
    return b.height - a.height;
}) 
weights.sort(function(a, b){
    return b.weight - a.weight;
})

var switches = new Array(parseInt(input[0]));
for (let index = 0; index < switches.length; index++) {
    switches[index] = false;
}

var ranks = new Array(parseInt(input[0]));
var rank = 1;
for (let index = 0; index < heights.length; index++) {
    let heightOrder = heights[index].order;
    let weightOrder = weights[index].order;

    if(heightOrder != weightOrder) {
        switches[heightOrder] = !switches[heightOrder]
        switches[weightOrder] = !switches[weightOrder]
    }

    ranks[heightOrder] = rank;
    ranks[weightOrder] = rank;

    var pass = false;
    for(let checkIndex = 0; checkIndex < heights.length; checkIndex++) {
        if(switches[checkIndex]) pass = true;
    }
    if(pass || isSameWithNext(index)) continue;

    if(rank !== index + 2) {
        rank = index + 2;
    }
}

var resultIndex = 0;
for(resultIndex; resultIndex < ranks.length; resultIndex++) {
    process.stdout.write(ranks[resultIndex] + " ");
}

function isSameWithNext(index) {
    if(index === input[0] - 1) return false;
    return (heights[index].height === heights[index + 1].height) &&
     (weights[index].weight === weights[index + 1].weight)
}