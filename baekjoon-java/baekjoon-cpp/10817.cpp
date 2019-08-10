#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	/*vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());

	cout << v[1] << '\n';*/

	//cout << (a + b + c) - max({ a,b,c }) - min({ a,b,c }) << '\n';

	cout << (a + b + c) - minmax({ a,b,c }).first - minmax({ a,b,c }).second << '\n';

	return 0;
}