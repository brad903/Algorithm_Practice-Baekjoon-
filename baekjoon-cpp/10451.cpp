#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> a(1001);
bool check[1001] = {0, };

void dfs(int x){
    check[x] = true;
    int y = a[x][0];
    if(check[y] == false){
        dfs(y);
    }
}

void init(bool *x){
    for(int i=0; i<=1000; i++){
        x[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            int u;
            scanf("%d", &u);
            a[i].push_back(u);
        }

        int ans = 0;
        for(int j=1; j<=n; j++){
            if(check[j] == false){
                dfs(j);
                ans++;
            }
        }

        printf("%d\n", ans);

        init(check);
        for(int i=0; i<=1000; i++){
            a[i].clear();
        }

    }

    return 0;
}