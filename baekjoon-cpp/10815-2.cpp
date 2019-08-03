#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// cin, cout사용할 경우 시간초과 발생

int main() {
	int n;
	scanf("%d", &n);

	vector<int> m;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		m.push_back(temp);
	}

	int l;
	scanf("%d", &l);

	sort(m.begin(), m.end());  // binary_search 이용하기 위해선 정렬이 되어있어야함!

	for (int i = 0; i < l; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", binary_search(m.begin(), m.end(), temp));
	}
	printf("\n");

	return 0;
}