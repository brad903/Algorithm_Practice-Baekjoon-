#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	string ans = "";

	for (int i = s.size()-1; i >= 0; i=i-3) {
		int temp = s[i]-'0';
		if (i - 1 >= 0) temp += (s[i - 1] - '0')*2;
		if (i - 2 >= 0) temp += (s[i - 2] - '0')*2*2;
		ans += to_string(temp);
	}

	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}