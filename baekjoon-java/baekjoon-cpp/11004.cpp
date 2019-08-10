#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    while(n--){
        long long num;
        scanf("%lld", &num);
        v.push_back(num);
    }

    nth_element(v.begin(), v.begin()+(k-1), v.end());

    printf("%lld\n", v[k-1]);

    return 0;
}