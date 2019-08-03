#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1,4,1,2,4,2,4,2,3,4,4 };
	for (int i = 1; i <= 5; i++) {
		auto it = find(a.begin(), a.end(), i);
		cout << i << "�� ��ġ: ";
		if (it == a.end()) {
			cout << "ã�� �� ����";
		}
		else {
			cout << (it-a.begin());   // � ���� ���� ���� ���� ��� ���� ó���� ���ͷ����͸� ��ȯ
		}
		cout << '\n';
	}

	cout << "-----------------------------------------------------------------\n";

	auto even = find_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 0;
	});
	auto odd = find_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 1;
	});

	cout << "ù ��° ¦��: " << (even - a.begin()) << '\n';
	cout << "ù ��° Ȧ��: " << (odd - a.begin()) << '\n';

	return 0;
}