#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> m;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		m.push_back(temp);
	}

	sort(m.begin(), m.end());

	int l;
	scanf("%d", &l);

	for (int i = 0; i < l; i++) {
		int temp;
		scanf("%d", &temp);

		auto l = lower_bound(m.begin(), m.end(), temp);
		auto r = upper_bound(m.begin(), m.end(), temp);

		printf("%d ", r - l);
	}
	printf("\n");

	return 0;
}