#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[300];
	int D[300];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	D[0] = A[0];
	D[1] = A[0] + A[1];
	D[2] = max(A[1] + A[2], A[0] + A[2]);
	for (int i = 3; i < n; i++) {
		D[i] = max(D[i - 2] + A[i], D[i - 3] + A[i - 1] + A[i]);
	}

	cout << D[n-1] << '\n';

	return 0;
}