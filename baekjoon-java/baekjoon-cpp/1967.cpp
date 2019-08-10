#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost){  // 구조체 생성자
    }
};
int check[100001];
vector<Edge> v[100001];
queue<int> q;
int cost_sum[100001];
int max_sum = 0;
int max_sum_index = 0;

void bfs(){
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++){
            int to_y = v[x][i].to;
            int cost_y = v[x][i].cost;
            if(check[to_y] == 0){
                check[to_y] = 1;
                cost_sum[to_y] = cost_sum[x] + cost_y;
                if(cost_sum[to_y] > max_sum) {
                    max_sum = cost_sum[to_y];
                    max_sum_index = to_y;
                }
                q.push(to_y);
            }
        }
    }
}

void init(int *a){
    for(int i=0; i<=100000; i++){
        a[i] = 0;
    }
}

int main(){
    int n;
    cin >> n;
    for(int g=0; g<n-1; g++){
        int i, a, b;
        cin >> i >> a >> b;
        v[i].push_back(Edge(a,b));
        v[a].push_back(Edge(i,b));
    }

    check[1] = true; q.push(1); cost_sum[1] = 0;
    bfs();

    memset(check, 0, sizeof(check));
    memset(cost_sum, 0, sizeof(cost_sum));
    max_sum = 0;

    check[max_sum_index] = true;
    q.push(max_sum_index);
    cost_sum[max_sum_index] = 0;
    bfs();

    cout << max_sum << '\n';

    return 0;
}