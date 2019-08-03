#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	
	string string_ab = a + b;
	long long front = stoll(string_ab);

	string string_cd = c + d;
	long long back = stoll(string_cd);

	cout << front + back;

	return 0;
}