#include <iostream>
#include <stdio.h>
using namespace std;

int map[101][101];
int visit[101][101];

int moveRow[4] = {0, 0, 1, -1};
int moveCol[4] = {1, -1, 0, 0};

int N;

void dfs(int height, int row, int col){
    pair<int, int> movedPoint;

    visit[row][col] = 1;
    for(int k=0; k<4; k++){
        movedPoint.first = row + moveRow[k];
        movedPoint.second = col + moveCol[k];
    
        if(movedPoint.first >= 0 && movedPoint.first < N && movedPoint.second >= 0 && movedPoint.second < N && visit[movedPoint.first][movedPoint.second] == 0){
            if(map[movedPoint.first][movedPoint.second] > height){
                dfs(height, movedPoint.first, movedPoint.second);
            }else {
                visit[movedPoint.first][movedPoint.second] = 1;
            }
        }
    }

}

void init(){
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            visit[i][j] = 0;
        }
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int maxLand = 0;
    for(int height = 0; height <= 100; height++){

        // 초기화
        int max = 0;
        init();

        for(int x=0; x<N; x++){
            for(int y=0; y<N; y++){
                if(visit[x][y] == 0 && map[x][y] > height) {
                    dfs(height, x,y);
                    max++;
                } else {
                    visit[x][y] = 1;
                }
            }
        }

        // cout << "height : " << height << ", " << "max : " << max << '\n';

        if(max > maxLand){
            maxLand = max;
        }

    }

    cout << maxLand << '\n';

    return 0;
}