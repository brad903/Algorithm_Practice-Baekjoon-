#include <iostream>
#include <string>
using namespace std;

long long D[5001];
long long mod = 1000000;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	s = " " + s;  // 문자열 1~n 자리수로 쓰기위해 하나 추가

	D[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0';  // 실제 정수값으로 바꾸기
		if (x >= 1 && x <= 9) {  // 한 자리 암호값인 경우
			D[i] = (D[i] + D[i - 1]) % mod;
		}
		if (i == 1) continue;  // 맨처음의 경우 두자리 불가능 
		if (s[i - 1] == '0') continue; // 앞자리가 0인 경우 두자리 불가능
		x = (s[i - 1] - '0') * 10 + (s[i] - '0'); // 두자리 수로 만들기
		if (x >= 10 && x <= 26) {  // 두 자리 암호값인 경우
			D[i] = (D[i - 2] + D[i]) % mod;
		}
	}

	cout << D[n] << '\n';

	return 0;
}