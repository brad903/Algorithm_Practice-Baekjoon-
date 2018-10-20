#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> a = { 1,3,4,5,7,7,8 };

	for (int i = 1; i <= 10; i++) {
		auto l = lower_bound(a.begin(), a.end(), i);
		auto r = upper_bound(a.begin(), a.end(), i);

		cout << i << ": ";
		cout << "lower_bound: " << (l - a.begin()) << ' ';
		cout << "upper_bound: " << (r - a.begin());
		cout << '\n';
	}

	return 0;
}