#include <algorithm>  // pair 관련 포함
#include <iostream>
using namespace std;

int main() {
	pair<int, int> p1;
	cout << p1.first << ' ' << p1.second << '\n';

	p1 = pair<int, int>(10, 20);
	cout << p1.first << ' ' << p1.second << '\n';

	p1 = pair<int, int>(30, 40);
	cout << p1.first << ' ' << p1.second << '\n';

	pair<int, int> p2(50, 60);
	cout << p2.first << ' ' << p2.second << '\n';

	
	pair<pair<int, int>, pair<int, int>> p =
		make_pair(make_pair(10, 20), make_pair(30, 40));

	cout << p.first.first << ' ' << p.first.second << ' ';
	cout << p.second.first << ' ' << p.second.second << ' ';

	return 0;
}