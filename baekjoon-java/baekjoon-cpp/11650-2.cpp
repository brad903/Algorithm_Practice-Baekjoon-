#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
        int x;
        int y;
    };

bool cmp(const Point &u, const Point &v){
    if(u.x < v.x) return true;
    else if(u.x == v.x) return u.y < v.y;
    else return false; 
}

int main(){
    vector<Point> v;
    int t;
    cin >> t;
    while(t--){
        Point p;
        cin >> p.x >> p.y;

        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto it=v.begin(); it!=v.end(); ++it){
        cout << (*it).x << (*it).y << '\n';
    }

    return 0;
}