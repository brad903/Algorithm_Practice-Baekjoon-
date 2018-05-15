#include <stdio.h>
#define max(a,b) ((a>b)? a:b)

int main() {
	int N;
	scanf("%d", &N);

	int D[10001];
	int A[10001];

	for (int i = 1; i <= N; i++) {
		int temp = 0;
		scanf("%d", &A[i]);
	}

	D[0] = 0;
	D[1] = A[1];
	D[2] = A[1] + A[2];
	for (int i = 3; i <= N; i++) {
		D[i] = D[i - 1];
		if (D[i] < D[i - 2] + A[i]) D[i] = D[i - 2] + A[i];
		if (D[i] < D[i - 3] + A[i - 1] + A[i]) D[i] = D[i - 3] + A[i - 1] + A[i];
	}

	printf("%d\n", D[N]);

	return 0;
}