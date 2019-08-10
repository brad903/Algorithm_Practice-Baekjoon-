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

	sort(s.begin(), s.end());  // 벡터에 넣을 때 거꾸로 넣어서 정렬한 후 출력할 떄는 제대로 다시 되돌려서 출력

	for (auto x : s) {
		cout << x.second << ' ' << x.first << '\n';
	}

	return 0;
}