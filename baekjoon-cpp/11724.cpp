#include <vector>
#include <cstdio>
using namespace std;

int check[1001];
vector<vector<int>> a(1001);
bool flag;

void dfs(int x){
    check[x] = true;
    if(a[x].size() == 0) flag = true;
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y] == false){
            dfs(y);
            flag = true;
        }
    }
    // printf("[테스트] x값 : %d, flag값 : %d\n", x, flag);
}

int main(){
    // 인접 리스트를 통한 구현
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        flag = false;
        dfs(i);
        if(flag == true) ans++;
    }
    if(ans==0) ans++;

    printf("%d\n", ans);

    return 0;
}