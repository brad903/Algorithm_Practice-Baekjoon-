#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];  // true: ������, false: �������� ����

// �����佺�׳׽��� ü �̿�
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

	// ���� ®�� �ڵ� - ��Ÿ�� ���� �߻�
	//vector<int> p;  // �Ҽ� ����
	//vector<bool> c(N + 1); // ���������� true
	//int n = N; // N���� �Ҽ�
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