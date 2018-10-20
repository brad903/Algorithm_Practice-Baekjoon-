#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> a = { 1,4,1,2,4,2,4,2,3,4,4 };
	for (int i = 1; i < 5; i++) {
		cout << i << "�� ����: " << count(a.begin(), a.end(), i);
		cout << '\n';
	}

	cout << "-----------------------------------------------------------------\n";

	int even = count_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 0;
	});
	int odd = count_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 1;
	});

	cout << "¦���� ����: " << even << '\n';
	cout << "Ȧ���� ����: " << odd << '\n';

	return 0;
}