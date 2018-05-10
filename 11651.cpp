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
		s.push_back(make_pair(b, a));
	}

	sort(s.begin(), s.end());  // pair�� �����ϸ� ���� first������� �����ϰ� ���� second ����

	for (auto x : s) {
		cout << x.second << ' ' << x.first << '\n';
	}

	return 0;
}