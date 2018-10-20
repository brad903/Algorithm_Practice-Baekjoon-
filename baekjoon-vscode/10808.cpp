#include <iostream>
#include <string>

using namespace std;

int main() {
	int alpa[26] = { 0, };
	//char test = 'a';
	//int test2 = test;
	//printf("%d", test2);  // a 97 z 122

	string cmd;
	cin >> cmd;

	int cmd_length = cmd.length();
	for (int i = 0; i < cmd_length; i++) {
		alpa[cmd[i] - 97]++;
	}

	for (int i = 0; i < sizeof(alpa)/sizeof(int); i++)
		cout << alpa[i] << " ";

	return 0;
}