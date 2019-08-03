#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];  // true: 지워짐, false: 지워지지 않음

// 에라토스테네스의 체 이용
int main() {
	check[0] = check[1] = true;
	for (int i = 2; i*i < MAX; i++) {
		if (check[i] == false) {
			for (int j = i * i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int M, N;
	cin >> M >> N;

	// 내가 짰던 코드 - 런타임 에러 발생
	//vector<int> p;  // 소수 저장
	//vector<bool> c(N + 1); // 지워졌으면 true
	//int n = N; // N까지 소수
	//for (int i = 2; i <= n; i++) {
	//	if (c[i] == false) {
	//		if (i >= M) p.push_back(i);
	//		for (int j = i * i; j <= n; j += i) {
	//			c[j] = true;
	//		}
	//	}
	//}
	//for (auto it = p.begin(); it != p.end(); ++it) {
	//	cout << *it << '\n';
	//}

	for (int i = M; i <= N; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}
	return 0;
}