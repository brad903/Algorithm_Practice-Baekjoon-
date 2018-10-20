#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N,0); 

	//for (int i = 0; i < N; i++) {  // 0으로 초기화
	//	v.push_back(0);
	//}

	for (int i = 0; i < M; i++) {
		int m, n, x;
		cin >> m >> n >> x;
		auto it = v.begin();
		fill(it + (m - 1), it + n, x);
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}