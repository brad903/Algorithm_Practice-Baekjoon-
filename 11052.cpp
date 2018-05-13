#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int d[10001], p[10001] = { 0, };
	d[0] = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 1; i <= n; i++) {
		for(int j=i; j>=1; j--){
			int temp = d[i - j] + p[j];
			d[i] = max(d[i], temp);
		}
	}

	printf("%d\n", d[n]);

	return 0;
}