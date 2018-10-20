#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int d[1001];

	d[0] = 1; // 없지만 d[2]의 경우를 고려하면 1로 생각할 수 있음
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
		d[i] %= 10007;
	}

	printf("%d\n", d[n]);

	return 0;
}