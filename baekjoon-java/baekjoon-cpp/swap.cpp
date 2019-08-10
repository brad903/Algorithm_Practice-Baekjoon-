#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a = 10, b = 20;
	cout << a << ' ' << b << '\n';
	swap(a, b);
	cout << a << ' ' << b << '\n';
	swap(a, b);
	cout << a << ' ' << b << '\n';

	cout << "-------------------------------------------------------------\n";

	vector<int> c = { 1,2 };
	vector<int> d = { 3,4 };
	cout << c[0] << ' ' << d[0] << '\n';
	swap(c, d);
	cout << c[0] << ' ' << d[0] << '\n';
	swap(c, d);
	cout << c[0] << ' ' << d[0] << '\n';

	return 0;
}