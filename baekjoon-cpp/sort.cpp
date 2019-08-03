#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(const int &u, const int &v) {
	return u > v;
}

void print(vector<int> x) {
	for (int a : x) {
		cout << a << ' ';
	}
	cout << '\n';
}

int main() {
	vector<int> a = { 5,3,2,1,4 };

	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	sort(a.begin(), a.end());

	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	vector<int> b = { 5,3,2,1,4 };

	sort(b.begin(), b.end(), greater<int>());
	print(b);
	sort(b.begin(), b.end(), cmp);
	print(b);
	sort(b.begin(), b.end(), [](int u, int v) {
		return u > v;
	});
	print(b);

	return 0;
}