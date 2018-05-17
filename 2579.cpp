#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[300];
	int D[300][3];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	D[0][1] = D[0][2] = A[0];
	D[1][1] = A[1];
	D[1][2] = D[0][1] + A[1];
	for (int i = 2; i < n; i++) {
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + A[i];
		D[i][2] = D[i - 1][1] + A[i];
	}

	cout << max(D[n - 1][1], D[n - 1][2]) << '\n';

	return 0;
}