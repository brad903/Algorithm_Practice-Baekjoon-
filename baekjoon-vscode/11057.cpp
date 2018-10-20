#include <iostream>
using namespace std;

int main() {
	long long D[1001][10];
	long long mod = 10007;

	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			D[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				D[i][j] += D[i - 1][k];
				D[i][j] %= mod;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += D[n][i];
	}
	sum %= mod;

	cout << sum << '\n';
	return 0;
}