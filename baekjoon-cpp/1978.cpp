#include <iostream>
using namespace std;

bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	int cnt = 0;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		if (prime(temp)) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}