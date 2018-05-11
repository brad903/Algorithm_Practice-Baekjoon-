#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int absolute(int a) {
	if (a < 0) return -a;
	else return a;
}

int sum(vector<int> v, int n) {
	if (n == 1) return 0;
	return sum(v, n - 1) + absolute(v[n - 2] - v[n - 1]);
}

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int max = 0;
	do {
		int temp = sum(v, n);
		if (temp > max) max = temp;
	} while (next_permutation(v.begin(), v.end()));

	cout << max << '\n';
	return 0;
}