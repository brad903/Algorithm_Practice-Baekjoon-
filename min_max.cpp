#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cout << min(2, 3) << '\n';
	cout << max(2, 3) << '\n';

	int a = 10, b = 20, c = 30;
	cout << min(min(a, b), c) << '\n';
	cout << min({ a,b,c }) << '\n';
	cout << max(max(a, b), c) << '\n';
	cout << max({ a,b,c }) << '\n';

	cout << "------------------------------------------------------\n";

	string u = "long string";
	string v = "short";

	cout << min(u, v) << '\n';
	cout << min(u, v, [](string u, string v) {
		return u.size() < v.size();
	}) << '\n';

	return 0;
}