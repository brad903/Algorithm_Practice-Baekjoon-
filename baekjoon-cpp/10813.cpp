#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(N,0);

	for (int i = 0; i < N; i++) {
		v[i] = i + 1;  // �̷��� ����ϱ� ���ؼ� �̸� v(N,0)�� ���� �̸� ���ϴ� ���� �־������
		//v.push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		swap(v[a - 1], v[b - 1]);
	}

	for (int x : v) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
