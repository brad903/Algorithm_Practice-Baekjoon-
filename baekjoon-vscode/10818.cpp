#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	/*auto min = min_element(v.begin(), v.end());
	auto max = max_element(v.begin(), v.end());*/

	auto minmax = minmax_element(v.begin(), v.end());

	/*cout << *min << ' ' << *max << '\n';*/
	cout << *minmax.first << ' ' << *minmax.second << '\n';

	return 0;
}