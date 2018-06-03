#include <cstdio>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int map[50][50];  // 땅이 있는 곳 여부
int check[50][50];   // 방문 여부 & 섬 번호 입력
queue<pair<int, int>> q;
vector<pair<int, int>> visit = {make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0), make_pair(1,1), make_pair(-1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(1,1)};

void bfs(int i, int j, int land_num){
    check[i][j] = land_num;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto x = q.front(); q.pop();
        for(int w=0; w<visit.size(); w++){
            int a, b;
            a = x.first + visit[w].first;
            b = x.second + visit[w].second;

        if(a >= 0 && b >= 0 & a<= 49 & b <= 49){
            if(map[a][b] == 1 && check[a][b] == 0){  // 땅이 있고 && 아직 방문하지 않았을 때
                check[a][b] = land_num;
                q.push(make_pair(a, b));
            }
        }
    }
}
}

void init(int (*a)[50]){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            a[i][j] = 0;
        }
    }
}

int main(){
    while(1){    
    int m, n;
    scanf("%d %d", &m, &n);

    if(m== 0 && n==0) break;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    // printf("입력완료\n");

    int land_num = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && check[i][j] == 0){
                bfs(i, j, land_num);
                land_num++;
            }
        }
    }

    printf("%d\n", land_num-1);

    init(check);
    init(map);
    }

    return 0;
}
