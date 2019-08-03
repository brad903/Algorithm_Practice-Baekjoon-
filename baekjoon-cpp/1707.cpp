#include <cstdio>
#include <vector>
using namespace std;

int check[20001] = {0, };
vector<vector<int>> a(20001);
bool flag = false;

void dfs(int x){
    if(check[x] == false) check[x] = 1;
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[x] == check[y]) { 
            flag = true;
            break;
        }
        if(check[y] == false){
            // if(check[x] == 1) check[y] = 2;
            // else if(check[x] == 2) check[y] = 1;
            check[y] = 3 - check[x];
            dfs(y);
        }
    }
}

void init(int *x){
    for(int i=1; i<=20000; i++){
        x[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for(int j=1; j<=n; j++){
            dfs(j); 
            if(flag == true) break;
        }

        if(flag == true) printf("NO\n");
        else printf("YES\n");

        flag = false;
        init(check);
        // a.clear();  // 여기서 문제
        for(int i=0; i<=20000; i++){
            a[i].clear();
        }
}
    return 0;

}