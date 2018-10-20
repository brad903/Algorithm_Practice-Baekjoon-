#include <set>
#include <iostream>
using namespace std;

// cout, cin을 이용했을 때 iose_base::sync_with_stdio(false); 이용했음에도 시간초과 발생!
// 10815-1에서 scanf, printf이용하여 해결

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	set<int> s;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		cout << s.count(temp) << ' ';
	}
	cout << '\n';

	return 0;
}