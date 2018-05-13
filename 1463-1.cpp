#include <cstdio>

int d[1000001];

void go_1(int n) {
	d[n] = d[n - 1] + 1;
	if (n % 2 == 0 && d[n / 2] + 1 < d[n]) d[n] = d[n / 2] + 1;
	if (n % 3 == 0 && d[n / 3] + 1 < d[n]) d[n] = d[n / 3] + 1;
}

int main() {
	d[1] = 0;
	d[2] = 1;

	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++) {
		go_1(i);
	}

	printf("%d\n", d[n]);

	return 0;
}