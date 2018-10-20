#include <iostream>
#include <string>
using namespace std;

int main() {
	int alpa[26] = { -1, };

	// -1로 초기화
	for (int i = 0; i < sizeof(alpa) / sizeof(int); i++) {
		alpa[i] = -1;
	}

	string cmd;
	cin >> cmd;
	
	int cmd_length = cmd.length();
	for (int i = 0; i < cmd_length; i++) {
		int num = cmd[i] - 97;
		if (alpa[num] == -1)
			alpa[num] = i;
	}

	for(int i=0; i<sizeof(alpa)/sizeof(int); i++){
		cout << alpa[i] << " ";
	}

	return 0;
}