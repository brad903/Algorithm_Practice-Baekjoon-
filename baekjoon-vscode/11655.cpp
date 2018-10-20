#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int data : s) {
		if (data >= 'a' && data <= 'z') {
			data += 13;
			if (data > 'z')
				data -= 26;
		}
		else if (data >= 'A' && data <= 'Z') {
			data += 13;
			if (data > 'Z')
				data -= 26;
		}
		cout << (char)data;
	}

	return 0;
}