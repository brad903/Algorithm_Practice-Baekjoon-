#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10000;
int cnt[MAX+1];

int main(){
    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int num;
        cin >> num;
        cnt[num]++;
    }

    // 메모리 제한되어 실패
    // vector<int> v;
    // while(n--){
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }
    // sort(v.begin(), v.end());
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i] << '\n';
    // }

    for(int j=1; j<=MAX; j++){
        // cnt 개수만큼 출력
        for(int k=1; k<=cnt[j]; k++){
            cout << j << '\n';
        }
    }
    
    return 0;
}