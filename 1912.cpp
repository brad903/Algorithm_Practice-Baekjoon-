#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> D(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	D[0] = A[0];
	for (int i = 1; i < n; i++) {
		D[i] = max(D[i - 1] + A[i], A[i]);
	}

	cout << *max_element(D.begin(), D.end()) << '\n';

	return 0;
}