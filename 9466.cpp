#include <cstdio>
#include <vector>
using namespace std;

vector<int> a(100001);
int check[100001] = {0, };
int pass = 0;  // 조를 이룬 사람들의 전체 수
vector<int> temp;

void dfs(int x, int c){
    // printf("x: %d, check[x]: %d, c : %d\n", x, check[x], c);
    if(check[x] == -1) return;  // -1로 처리된 얘가 있으면 바로 끝내버려
    if(check[x] == c && x == c) {  // 사이클이 이루어져 조가 만들어진 경우
        // if(x != c) return; // 사이클과 아닌 것이 섞여잇는 경우
        pass += temp.size();
        for(int i=0; i<temp.size(); i++){
            check[temp[i]] = -1;
        }
        return;
    }
    // if(x != c && a[x] == x) return;  // 다른 얘가 혼자 조하겠다고 한 얘를 선택한 경우
    check[x] = c;
    temp.push_back(x);
    dfs(a[x], c);
}

void init(int *a){
    for(int i=0; i<=100000; i++){
        a[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
        scanf("%d", &m);

        for(int i=1; i<=m; i++){
            int num;
            scanf("%d", &num);
            a[i] = num;
        }

        for(int i=1; i<=m; i++){
            if(a[i] == i){  // 자기 혼자 조 하는 경우
                check[i] = -1;
                pass += 1;
            }
        }

        for(int i=1; i<=m; i++){
            if(check[i] != -1){
                int c = i;
                dfs(i, c);
                temp.clear();
            }
        }

        printf("%d\n", m-pass);

        pass = 0;
        init(check);
        a.clear();
    }
    
    return 0;
}