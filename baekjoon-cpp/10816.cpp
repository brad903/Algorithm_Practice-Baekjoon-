#include <set>
#include <iostream>
using namespace std;

// 시간 초과 발생.. 
// 이분 탐색 관련해서 좀 더 공부하고 해결하는 것으로..

int main() {
	int n;
	scanf("%d", &n);

	multiset<int> s;  // multiset을 이용하여 집합 내 원소 중복 허용

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		s.insert(temp);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", s.count(temp));
	}
	printf("\n");

	return 0;
}