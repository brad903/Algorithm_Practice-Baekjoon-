#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int map[100][100];
int dist[100][100];
int check[100][100];  // 섬 번호 초기화

int n; // map의 크기
queue<pair<int,int>> q;  // 그룹 나누기 위한 용도
queue<pair<int,int>> q2; // 거리 재기위한 용도
vector<pair<int, int>> visit = {make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0)};

void bfs(int i, int j, int land_num){
    check[i][j] = land_num;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto x = q.front(); q.pop();

        for(int w=0; w<visit.size(); w++){
            int a, b;
            a = x.first + visit[w].first;
            b = x.second + visit[w].second;

            if(a >= 0 && b >= 0 && a < n && b < n){
                if(map[a][b] == 1 && check[a][b] == 0){
                    check[a][b] = land_num;
                    q.push(make_pair(a,b));
                }
            }
        }
    }
}

void bfs2(){
    while(!q2.empty()){
        auto x = q2.front(); q2.pop();

        for(int w=0; w<visit.size(); w++){
                int a, b;
                a = x.first + visit[w].first;
                b = x.second + visit[w].second;

                if(a >= 0 && b >= 0 && a < n && b < n){
                    if(check[a][b] == 0){
                        dist[a][b] = dist[x.first][x.second] + 1;
                        check[a][b] = check[x.first][x.second];
                        q2.push(make_pair(a,b));
                    }
                }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            scanf("%d", &map[i][j]);

            if(map[i][j] == 1) q2.push(make_pair(i,j));  // 육지가 있으면 q에 넣어둠
        }
    }

    int land_num = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && check[i][j] == 0){
                bfs(i, j, land_num);
                land_num++;
            }
        }
    }

bfs2(); // dist, check 빈 곳 채우기(거리 재기위함)

int ans = 2*n;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        for(int k=0; k<visit.size(); k++){
            int a = i + visit[k].first;
            int b = j + visit[k].second;

            if(a >= 0 && b >= 0 && a < n && b < n){
                if(check[i][j] != check[a][b] && ans > dist[i][j]+dist[a][b]) ans = dist[i][j]+dist[a][b];
            }
        }
    }
}

printf("%d\n", ans);

    return 0;
}