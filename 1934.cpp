#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		int g = gcd(x, y);

		long long l = g * (x / g) * (y / g);

		cout << l << '\n';
	}

	return 0;
}