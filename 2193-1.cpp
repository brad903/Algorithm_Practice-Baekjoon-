#include <iostream>
using namespace std;

int main() {
	long long D[91][2];

	D[0][0] = 0, D[0][1] = 0;
	D[1][0] = 0, D[1][1] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	cout << D[n][0] + D[n][1] << '\n';

	return 0;
}