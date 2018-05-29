#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int absolute(int x){
    if(x<0) return -x;
    return x;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> a(n);

    // first에는 입력값 넣고, second에는 순서를 넣음
    for(int i=0; i<n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int ans=0;
    for(int j=0; j<n; j++){
        if(ans < a[j].second - j) ans = a[j].second-j;
    }

    printf("%d\n", ans+1);

    return 0;
}