var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

var people = new Array();

for(let index = 1; index <= input[0]; index++) {
    var splitted = input[index].split(' ');
    people.push({"weight": splitted[0], "height": splitted[1]});
}

for(let i = 0; i < people.length; i++) {
    var rank = 1;
    for(let j = 0; j < people.length; j++) {
        if(i === j) continue;
        if((people[i].weight < people[j].weight) && (people[i].height < people[j].height)) {
            rank++;
        }
    }
    process.stdout.write(rank + " ");
}   