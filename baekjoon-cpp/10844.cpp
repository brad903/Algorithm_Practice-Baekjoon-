#include <iostream>
using namespace std;

int main() {
	long long D[101][10];

	int n;
	cin >> n;

	D[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 8; j++) {
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];
			D[i][j] %= 1000000000;
		}
		D[i][0] = D[i - 1][1];
		D[i][9] = D[i - 1][8];
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += D[n][i];
	}
	sum %= 1000000000;

	cout << sum << '\n';

	return 0;
}