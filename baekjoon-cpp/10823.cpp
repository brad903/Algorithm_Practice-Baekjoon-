#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string line;
	string s;

	while (cin >> s) {
		line += s;
	}

	istringstream sin(line);  // sstream헤더 필요

	int sum = 0;
	while (getline(sin, s, ',')) {
		sum += stoi(s);
	}

	cout << sum << "\n";
}