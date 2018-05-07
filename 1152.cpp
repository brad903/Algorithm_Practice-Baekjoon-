#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	int cnt = 0;

	while (cin >> s) {
		cnt += 1;
	}

	cout << cnt << "\n";

	return 0;
}