#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<int> v;
		for (int i = 3; i <= n/2; i=i+2) {
			if (prime(i) && prime(n - i)) {
				v.push_back((n - i) - i);
			}
		}

		if (v.size() == 0) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
		else {
			int diff =  *max_element(v.begin(), v.end());
			int a = (n - diff) / 2;
			cout << n << " = " << a << " + " << n - a << '\n';
		}

		v.clear();
	}


	return 0;
}