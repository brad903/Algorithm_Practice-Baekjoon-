#include <cstdio>
#include <vector>
using namespace std;

int a[100001];
int check[100001];
int num[100001]; // 각 스텝별 카운트
int pass = 0;  // 조를 이룬 사람들의 전체 수
int cnt = 0;

void dfs(int x, int c){
    if(check[x] == c) { 
        pass += (cnt - num[x] + 1);
        return;
    }
    if(check[x] != 0) return;
    cnt++;
    num[x] = cnt;
    check[x] = c;
    // printf("x: %d, a[x]: %d, check[x]: %d, num[x]: %d, cnt: %d\n", x, a[x], check[x], num[x], cnt);
    dfs(a[x], c);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
        scanf("%d", &m);

        for(int i=1; i<=m; i++){
            int x;
            scanf("%d", &x);
            a[i] = x;
            num[i] = 0;
            check[i] = 0;
        }
        
        for(int i=1; i<=m; i++){
            cnt = 0;
            if(check[i] == 0){
                int c = i;
                dfs(i, c);
            }
        }

        printf("%d\n", m - pass);

        pass = 0;
    }
    
    return 0;
}