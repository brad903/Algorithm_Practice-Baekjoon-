#include <iostream>
using namespace std;

int main() {
	long long D[91];

	int n;
	cin >> n;

	D[0] = 0;
	D[1] = 1;
	for (int i = 2; i <= n; i++) {
		D[i] = D[i - 1] + D[i - 2];
	}

	cout << D[n] << '\n';

	return 0;
}