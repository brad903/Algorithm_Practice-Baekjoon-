#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, string> dic = { { 0, "000" },{ 1, "001" },{ 2,"010" },{ 3,"011" },{ 4,"100" },
{ 5,"101" },{ 6,"110" },{ 7,"111" }
};

int main() {
	string s;
	cin >> s;

	string ans;

	for (int i = 0; i < s.size(); i++) {
		ans += dic[s[i] - '0'];
	}
	
	bool flag = false;
	for (int i = 0; i < ans.size(); i++) {
		// 0�� ��� ����ó��
		if (ans == "000") {
			cout << '0';
			break;
		}

		// 2������ ��Ÿ�� �� ���� 0���� �� ��Ÿ���� ����
		if (ans[i] == '1') {
			for (int j = i; j < ans.size(); j++) {
				cout << ans[j];
			}
			flag = true;
		}
		if (flag) break;
	}
	cout << '\n';

	return 0;
}