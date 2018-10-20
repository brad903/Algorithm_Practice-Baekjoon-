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
    int last=1; // for 반복문 안 마지막 cnt값 기억
    long long ans=v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i-1] != v[i]){
            if(last < cnt){
                ans = v[i-1];
                last = cnt;
            } 
            cnt = 1;
        } else {
            cnt++;
        }
    }

    if(last < cnt) ans = v[v.size()-1];

    cout << ans << '\n';

    return 0;
}