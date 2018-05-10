#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<tuple<int, int, int,string>> v;

	for (int i = 0; i < n; i++) {
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v.push_back(make_tuple(-a, b, -c,name));
	}

	sort(v.begin(), v.end());

	for (auto x : v) {
		cout << get<3>(x) << '\n';
	}

	return 0;
}