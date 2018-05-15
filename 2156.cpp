#include <stdio.h>
#define max(a,b) ((a>b)? a:b)

int main() {
	int N;
	scanf("%d", &N);

	int D[10001][3];
	int A[10001];

	for(int i=1; i<=N; i++) {
		int temp = 0;
		scanf("%d", &A[i]);
	}

	D[0][0] = D[0][1] = D[0][2] = 0;
	for (int i = 1; i <= N; i++) {
		D[i][0] = max(max(D[i - 1][0], D[i - 1][1]), D[i - 1][2]);
		D[i][1] = D[i - 1][0] + A[i];
		D[i][2] = D[i - 1][1] + A[i];
	}

	int ans = 0;
	ans = max(D[N][0], max(D[N][1], D[N][2]));

	printf("%d\n", ans);

	return 0;
}