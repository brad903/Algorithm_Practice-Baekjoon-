#include <functional>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	function<int(int)> p = [&](int x) {
		if (x == 0) return 0;
		if (x == 1) return 1;
		else return p(x - 2) + p(x - 1);
	};

	cout << p(n) << "\n";

	return 0;
}