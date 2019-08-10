#include <iostream>
#include <string>
using namespace std;

long long D[5001];
long long mod = 1000000;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	s = " " + s;  // ���ڿ� 1~n �ڸ����� �������� �ϳ� �߰�

	D[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0';  // ���� ���������� �ٲٱ�
		if (x >= 1 && x <= 9) {  // �� �ڸ� ��ȣ���� ���
			D[i] = (D[i] + D[i - 1]) % mod;
		}
		if (i == 1) continue;  // ��ó���� ��� ���ڸ� �Ұ��� 
		if (s[i - 1] == '0') continue; // ���ڸ��� 0�� ��� ���ڸ� �Ұ���
		x = (s[i - 1] - '0') * 10 + (s[i] - '0'); // ���ڸ� ���� �����
		if (x >= 10 && x <= 26) {  // �� �ڸ� ��ȣ���� ���
			D[i] = (D[i - 2] + D[i]) % mod;
		}
	}

	cout << D[n] << '\n';

	return 0;
}