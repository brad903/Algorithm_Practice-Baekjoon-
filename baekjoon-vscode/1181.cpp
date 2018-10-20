#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	/*sort(v.begin(), v.end(), [](string a, string b) {
		if (a.size() < b.size())
			return true;
		else if (a.size() == b.size())
			return a < b;
		else
			return false;
	});*/

	//sort(v.begin(), v.end(), [](string u, string v) {
	//	if (u.size() == v.size()) {
	//		return u < v;
	//	}
	//	else {
	//		// �̷��� ǥ���Ͽ� ������ true, false ���� ��þ����൵ ��
	//		return u.size() < v.size();
	//	}
	//});

	/*sort(v.begin(), v.end(), [](string u, string v) {
		return (u.size() < v.size()) || (u.size() == v.size() && u < v);
	});*/

	sort(v.begin(), v.end(), [](string u, string v) {
		return make_pair(u.size(), u) < make_pair(v.size(), v);
	});

	auto last = unique(v.begin(), v.end());
	v.erase(last, v.end());

	for (string x : v) {
		cout << x << '\n';
	}

	return 0;
}