#include <set>
#include <iostream>
using namespace std;

// cout, cin�� �̿����� �� iose_base::sync_with_stdio(false); �̿��������� �ð��ʰ� �߻�!
// 10815-1���� scanf, printf�̿��Ͽ� �ذ�

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