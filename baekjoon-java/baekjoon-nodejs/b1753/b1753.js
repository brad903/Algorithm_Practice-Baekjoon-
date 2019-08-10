var fs = require('fs');
var input = fs.readFileSync('./stdin').toString().split('\n');

var first = input.shift().split(' ');
var v = parseInt(first[0]);
var e = parseInt(first[1]);
var start = parseInt(input.shift());

var connections = initConnections(v, e);


function initConnections(v, e) {
    var connections = new Array(v);
    for(let i = 0; i < v; i++) {
        connections[i] = new Array(v).fill(0);
    }

    for(let j = 0; j < e; j++) {
        let splitted = input.shift().split(' ');
        let start = parseInt(splitted[0]);
        let end = parseInt(splitted[1]);
        let weight = parseInt(splitted[2]);
        connections[start - 1][end - 1] = weight;
    }
    return connections;
}