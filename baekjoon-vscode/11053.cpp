#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int D[1001];
	int A[1001];

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	D[1] = 1;
	for (int i = 2; i <= n; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				D[i] = max(D[i], D[j] + 1);
			}
		}
	}

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, D[i]);
	}
	
	cout << ans << '\n';
	return 0;
}