#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;


void print(vector<vector<int>> lines) {
    int lastLineIndex = lines.size()-1;
    int lastLineLength = lines[lastLineIndex].size();
    int finalIndex = lines[lastLineIndex][lastLineLength-1]+1;
     for(int i = 0; i < lines.size(); i++) {
        vector<int> line = lines[i];
        int index = 0;
        int start = 0;
        int last = line[index];
        for(int j = start; j <= last; j++) {
            if(j == last) {
                if(j == finalIndex) {
                    break;
                }
                cout << "*";
                start = last + 1;
                if(index+1 == line.size()) {
                    last = finalIndex;
                    continue;
                }
                index = index + 1;
                last = line[index];
                continue;
            }
            cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int answer;
    scanf("%d", &answer);
    answer = answer / 3;
    answer = log2 (answer) + 1;
    vector<vector<int>> lines = {{2}, {1,3}, {0,1,2,3,4}};
    for(int i = 1; i < answer; i++) {
        int lineSize = lines.size();
        vector<vector<int>> outStorage;
        // 앞쪽 라인
        for(int x = 0; x < lineSize; x++) {
            vector<int> inStorage;
            for(int y = 0; y < lines[x].size(); y++) {
                inStorage.push_back(lines[x][y] + 3 * pow(2, i-1));
            }
            outStorage.push_back(inStorage);
        }
        // 뒤쪽 라인
        for(int x = 0; x < lineSize; x++) {
            vector<int> inStorage;
            for(int y = 0; y < lines[x].size(); y++) {
                inStorage.push_back(lines[x][y]); 
            }
            for(int y = 0; y < lines[x].size(); y++) {
                inStorage.push_back(lines[x][y] + 3 * pow(2, i)); 
            }
            outStorage.push_back(inStorage);
        }
        lines = outStorage;
    }
    print(lines);
    return 0;
}

// cout << line.size() << '\n';