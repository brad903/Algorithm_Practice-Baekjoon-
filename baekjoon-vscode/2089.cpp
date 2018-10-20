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
			if (n % -2 == 0) {  // ��� ¦��, ���� ¦���� ��
				n = n / (-2);
				ans += "0";
			}
			else { // ��� Ȧ��, ���� Ȧ���� ��
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