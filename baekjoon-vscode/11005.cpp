#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, B;
	cin >> N >> B;

	string s = "";

	while (N / B != 0) {
		int temp;
		temp = N % B;
		N = N / B;

		if (temp >= 0 && temp < 10) {
			s += (char)(temp + '0');
		}
		else {
			s += (char)(temp - 10 + 'A');
		}
	}

	// N/B = 0일 때 마지막 경우 고려
	if (N >= 0 && N < 10) {
		s += (char)(N + '0');
	}
	else {
		s += (char)(N - 10 + 'A');
	}

	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}
	cout << '\n';

	return 0;
}