#include <iostream>
using namespace std;



int main() {
	const int MAX = 100000;
	bool check[MAX + 1];  // true : 지워짐, false : 지워지지 않음
	int prime[MAX];
	int pn;


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
		cin >> n;
		if (n == 0) break;

		for (int i = 1; i < pn; i++) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n-prime[i]  << '\n';
				break;
			}
		}
	}

	return 0;
}