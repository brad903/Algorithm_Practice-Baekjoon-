#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int len=0;
	for (int i = 0; i < s.length(); i++) {
		len += 1;
	}
	printf("%d\n", len);

	return 0;
}