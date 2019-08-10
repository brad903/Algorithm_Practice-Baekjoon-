#include <iostream>
using namespace std;

//long long factorial(int n) {
//	if (n == 1) return 1;
//	return n * factorial(n - 1);
//}

long long factorial(int n) {
	int val = 1;
	for (int i = n; i >= 1; i--) {
		val *= i;
	}
	return val;
}

int main() {
	int n;
	cin >> n;

	cout << factorial(n) << '\n';

	return 0;
}