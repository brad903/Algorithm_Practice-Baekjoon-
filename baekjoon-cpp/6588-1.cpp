#include <cstdio>
using namespace std;

const long long MAX = 1000000;
bool check[MAX + 1] = {0, };  // true : 소수가 아닌 수, false : 소수인 수

int main() {
	int prime[MAX];
	int pn=0;

// 에라토스테네스의 체를 이용
	for (long long i = 2; i*i < MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (long long j = i * i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 1; i < pn; i++) {
			if (check[n - prime[i]] == false) {
				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				// cout << n << " = " << prime[i] << " + " << n-prime[i]  << '\n';
				break;
			}
		}
	}

	return 0;
}