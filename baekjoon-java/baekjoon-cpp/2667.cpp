#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int map[25][25];  // 집 있는 곳 여부
int check[25][25];   // 방문 여부 & 단지 번호 입력
queue<pair<int, int>> q;
vector<pair<int, int>> visit = {make_pair(0,1), make_pair(0,-1), make_pair(1,0), make_pair(-1,0)};
vector<int> house;

void bfs(int i, int j, int apt_num){
    int house_num = 0;
    check[i][j] = apt_num;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto x = q.front(); q.pop();
        house_num++;
        // printf("x의 값 : (%d, %d), apt_num : %d\n", x.first, x.second, apt_num);
        for(int w=0; w<visit.size(); w++){
            int a, b;
            a = x.first + visit[w].first;
            b = x.second + visit[w].second;

        // if(apt_num == 1){
        //     printf("apt_num ==1 : %d %d\n", a, b);
        // }

        if(a >= 0 && b >= 0 & a<= 24 & b <= 24){
            if(map[a][b] == 1 && check[a][b] == 0){  // 집이 있고 && 아직 방문하지 않았을 때
                check[a][b] = apt_num;
                q.push(make_pair(a, b));
            }
        }
    }
}
    house.push_back(house_num);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    int apt_num = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && check[i][j] == 0){
                bfs(i, j, apt_num);
                apt_num++;
            }
        }
    }

    printf("%d\n", apt_num-1);
    sort(house.begin(), house.end());
    for(auto it=house.begin(); it!=house.end(); ++it){
        printf("%d\n", *it);
    }

return 0;
}
