#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;

	string ans = "";

	if (n == 0) ans = "0";
	else{
		while (n != 0) {
			if (n % -2 == 0) {  // ¾ç¼ö Â¦¼ö, À½¼ö Â¦¼öÀÏ ¶§
				n = n / (-2);
				ans += "0";
			}
			else { // ¾ç¼ö È¦¼ö, À½¼ö È¦¼öÀÏ ¶§
				n = (n - 1) / (-2);
				ans += "1";
			}
		}
	}

	reverse(ans.begin(), ans.end());

	for(int i=0; i<ans.size(); i++){
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}