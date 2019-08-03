#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n+1);
		long long sum = 0;
		// n번 vector에 입력
		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			v[i] = temp;
		}

		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				sum += gcd(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}