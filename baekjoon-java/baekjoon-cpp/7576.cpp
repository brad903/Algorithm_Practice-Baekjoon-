#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int map[1000][1000];
int check[1000][1000];
int m, n;

queue<pair<int,int>> q;
vector<pair<int, int>> visit = {make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0)};

void bfs(){
    while(!q.empty()){
        auto x = q.front(); q.pop();

        for(int w=0; w<visit.size(); w++){
            int a, b;
            a = x.first + visit[w].first;
            b = x.second + visit[w].second;

            if(a >= 0 && b >= 0 && a < n && b < m){
                if(map[a][b] == 0 && check[a][b] == 0){
                    check[a][b] = check[x.first][x.second] + 1;
                    q.push(make_pair(a,b));
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &m, &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) q.push(make_pair(i,j)); // 1인 것 미리 q에 넣어둠
        }
    }

    bfs();

    int ans = 0;
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && check[i][j] == 0) flag = true;
            if(check[i][j] > ans) ans = check[i][j];
        }
    }
    
    if(flag) printf("-1\n");
    else printf("%d\n", ans);

    

    return 0;
}