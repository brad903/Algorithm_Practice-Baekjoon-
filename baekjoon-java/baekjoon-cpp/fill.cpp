#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> a = { 1,4,1,2,4,2,4,2,3,4,4 };
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	fill(a.begin(), a.end(), 0);  // ��� ���� 0���� ����
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}