#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	auto is_less = [&](int number) {
			return number < x;
	};

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if(is_less(temp))
			cout << temp << " ";
	}
	cout << "\n";

	return 0;
}