#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
vector<bool> check(100000);

int make_num(string s, int m){
    int num = 0;
    for(int i=0; i<s.size(); i++){
        int sub_num = 1;
        for(int j=0; j<m; j++){
            sub_num *= (s[i]-'0');
        }
        num += sub_num;
    }
    return num;
}

void dfs(string s, int m){
    int x = make_num(s, m);
    if(check[x] == true) {
        for(int i=1; i<=v.size(); i++){
            if(v[i] == x) {
                cout << i-1 << '\n';
                return;
            }
        }
    }
    v.push_back(x);
    check[x] = true;
    dfs(to_string(x), m);
}

int main(){
    string a;
    int m;
    cin >> a >> m;

    v.push_back(0); // v[0]을 채워주기 위함
    v.push_back(stoi(a));
    check[stoi(a)] = true;
    dfs(a, m);

    // for(auto it=v.begin(); it!=v.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << '\n';

    return 0;
}