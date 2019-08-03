#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int map[100][100];
int check[100][100];

queue<pair<int,int>> q;
vector<pair<int, int>> visit = {make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0)};

int cnt = 1;
void bfs(pair<int,int> prev){
    q.push(prev);
    while(!q.empty()){
        auto x = q.front(); q.pop();
        for(int w=0; w<visit.size(); w++){
            int a, b;
            a = x.first + visit[w].first;
            b = x.second + visit[w].second;

            if(a >= 0 && b >= 0 && a < 100 && b < 100){
                if(map[a][b] == 1 && check[a][b] == 0){ // 길이 있고 && 아직 방문하지 않았을 때
                    check[a][b] = check[x.first][x.second] + 1;
                    q.push(make_pair(a,b));
                }
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    check[0][0] = 1;
    bfs(make_pair(0,0));

    printf("%d\n", check[n-1][m-1]);

    return 0;
}