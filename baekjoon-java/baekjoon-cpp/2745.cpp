#include <iostream>
#include <string>
using namespace std;

int s_to_i(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if(c>='A' && c <= 'Z') {
		return c - 'A' + 10;
	}
}

int main() {
	string s;
	int B;
	cin >> s >> B;

	int ans = s_to_i(s[0]);
	for (int i = 1; i<s.size(); i++) {
		ans = ans * B + s_to_i(s[i]);
	}

	cout << ans << '\n';

	return 0;
}