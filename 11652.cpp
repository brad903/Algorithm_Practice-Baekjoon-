#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main(){
    int n;
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int cnt=1;
    long long ans=1;
    for(int i=1; i<v.size(); i++){
        if(v[i-1] != v[i]){
            if(ans < cnt) ans = v[i-1];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if(ans < cnt) ans = v[v.size()-1];

    cout << ans << '\n';

    return 0;
}