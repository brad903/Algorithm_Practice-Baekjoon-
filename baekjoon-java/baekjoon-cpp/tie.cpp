#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

int main() {
	auto t = make_tuple(10, 20, 30);

	int x = get<0>(t);
	int y = get<1>(t);
	int z = get<2>(t);

	cout << x << ' ' << y << ' ' << z << '\n';


	tie(x, y) = make_pair(y, x);  // tie�Լ��� �̿��� swap�Լ� ����

	cout << x << ' ' << y << ' ' << z << '\n';

	return 0;
}