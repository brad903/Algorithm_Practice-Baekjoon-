#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

long long a[100001];
long long b[100001];
long long D[100001][3];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int l = 0; l < n; l++) {  // n번 시행
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++) {  // a에 c개 입력
			scanf("%lld", &a[j]);
		}

		for (int k = 1; k <= c; k++) {  // b에 c개 입력
			scanf("%lld", &b[k]);
		}

		D[0][0] = D[0][1] = D[0][2] = 0;
		for (int i = 1; i <= c; i++) {
			D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
			D[i][1] = max(D[i - 1][2], D[i - 1][0]) + a[i];
			D[i][2] = max(D[i - 1][1], D[i - 1][0]) + b[i];
		}

		long long ans = 0;
		for(int i=1; i<=c; i++){
			ans = max(max(ans, D[i][0]), max(D[i][1], D[i][2]));
		}

		printf("%lld\n", ans);
	}


	return 0;
}