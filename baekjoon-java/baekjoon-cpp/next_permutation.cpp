#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> a = { 3,1,2 };
	sort(a.begin(), a.end()); // ������ ���� ������ 3 1 2, 3 2 1 ��� �ۿ� �ȳ���

	do {
		for (int x : a) {
			cout << x << ' ';
		}
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));  // ���� ������ ������ ���� ������ ����

	return 0;
}