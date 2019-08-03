#include <set>
#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	set<int> s;

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