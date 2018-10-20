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
	int ans=0;
	for(int k=2; k<=n; k++){
		int ans1 = 1, ans2 = 1;
		for (int a = 2; a <= k; a++) {
			D[a] = 0;
			// 증가하는 부분 수열 결정
			for (int b = 1; b < a; b++) {
				if (A[b] < A[a] && D[a] < D[b] + 1) {
					D[a] = D[b] + 1;
				}
			}
			// 증가하는 부분 수열 중 가장 길이 긴 것 선택
			ans1 = max(ans1, D[a]);
		}

		for (int c = k; c <= n; c++) {
			D[c] = 1;
			// 감소하는 부분 수열 결정
			for (int d = k; d < c; d++) {
				if (A[d] > A[c] && D[c] < D[d] + 1) {
					D[c] = D[d] + 1;
				}

				// 바이토닉 수열이 아닌 경우 제외
				for (int e = c + 1; e <= n; e++) {
					if (A[e] > A[c]) D[c] = 1;
				}
			}
			// 증가하는 부분 수열 중 가장 길이 긴 것 선택
			ans2 = max(ans2, D[c]);
		}

		printf("ans1 : %d, ans 2: %d, k: %d\n", ans1, ans2,k);
		if (ans1 != 1 && ans2 != 1) {
			ans = max(ans, ans1 + ans2 - 1);
		}
	}

	cout << ans << '\n';
	return 0;
}