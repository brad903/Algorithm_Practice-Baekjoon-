#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	int base = 1;
	for (int i = 0; i < 3; i++) {
		base *= 5;
		cnt += n / base;
	}

	cout << cnt << '\n';

	return 0;
}