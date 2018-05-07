#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	string ab = a + b;
	string cd = c + d;

	long long front = stoll(ab);
	long long back = stoll(cd);

	long long sum = 0;
	sum = front + back;

	cout << sum << "\n";

	return 0;
}