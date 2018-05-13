#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int d[11];

	d[1] = 1; 
	d[2] = 2;
	d[3] = 4;
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 4; j <= m; j++) {
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		}
		printf("%d\n", d[m]);
	}

	return 0;
}

