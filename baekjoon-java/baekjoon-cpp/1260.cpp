#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int check[1001] = {0, };
vector<vector<int>> a(1001);
queue<int> q;

void dfs(int x){
    check[x] = true;
    printf("%d ", x);
    sort(a[x].begin(), a[x].end());  // 입력 받은 순을 오름차순으로 정렬
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y] == false){
            dfs(y);
        }
    }
}

void bfs(int x){
check[x] = true; q.push(x);
while(!q.empty()){
    int z = q.front(); q.pop();
    printf("%d ", z);
    sort(a[z].begin(), a[z].end());  // 입력 받은 순을 오름차순으로 정렬
    for(int i=0; i<a[z].size(); i++){
        int y = a[z][i];
        if(check[y] == false){
            q.push(y); check[y]=true;
        }
    }
}
}

// 배열 정리
void init(int* a){
    for(int i=0; i<=1000; i++){
        a[i] = 0;
    }
}

int main(){
    // 인접리스트를 통한 구현
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }


    dfs(x);
    printf("\n");

    // check배열 초기화
    init(check);

    bfs(x);
    printf("\n");

    return 0;
}