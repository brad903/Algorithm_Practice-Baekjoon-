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

	sort(s.begin(), s.end());  // pair를 정렬하면 먼저 first순서대로 정렬하고 이후 second 정렬

	for (auto x : s) {
		cout << x.second << ' ' << x.first << '\n';
	}

	return 0;
}