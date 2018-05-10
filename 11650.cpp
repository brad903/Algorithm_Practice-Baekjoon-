#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> s;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		s.push_back(make_pair(a, b));
	}

	sort(s.begin(), s.end());  // pair�� �����ϸ� ���� first������� �����ϰ� ���� second ����

	for (auto x : s) {
		cout << x.first << ' ' << x.second << '\n';
	}

	return 0;
}