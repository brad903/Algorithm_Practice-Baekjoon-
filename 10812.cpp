#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int a, b, x;
		cin >> a >> b >> x;

		rotate(v.begin() + (a - 1), v.begin() + (x - 1), v.begin() + b);
	}

	for(int x : v) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}