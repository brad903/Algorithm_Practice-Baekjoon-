#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;

	int sum = 0;
	while (getline(cin, s, ',')) {
		sum += stoi(s);
	}

	cout << sum << "\n";
}