#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> count(long long n) {
	int count_2 = 0;
	int count_5 = 0;

	for (long long i = 2; i <= n; i *= 2) {
		count_2 += n / i;
	}
	for (long long j = 5; j <= n; j *= 5) {
		count_5 += n / j;
	}

	return make_pair(count_2, count_5);
}

int main() {
	long long a, b;
	cin >> a >> b;

	pair<int, int> n, m, nm;
	n = count(a);
	m = count(b);
	nm = count(a - b);

	cout << min(n.first - m.first - nm.first, n.second - m.second - nm.second) << '\n';

	return 0;
}