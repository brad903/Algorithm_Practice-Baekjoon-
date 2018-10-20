#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	auto last = unique(a.begin(), a.end());  // unique�� �ߺ��� ������ ���� end ���ͷ����͸� ��ȯ
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	for (auto it = a.begin(); it != last; ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	cout << "-------------------------------------------------------------\n";

	vector<int> b = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };

	auto last2 = unique(b.begin(), b.end());
	b.erase(last2, b.end()); // last���� end���� ���ʿ��� �κ� ����
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << "-------------------------------------------------------------\n";
	// �̹��� c�� �̸� ������ �� unique�Լ��� �Ẹ�ڽ��ϴ�!
	vector<int> c = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };

	sort(c.begin(), c.end());  // �������� ����
	auto last3 = unique(c.begin(), c.end());
	c.erase(last3, c.end()); // last���� end���� ���ʿ��� �κ� ����
	for (int x : c) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}