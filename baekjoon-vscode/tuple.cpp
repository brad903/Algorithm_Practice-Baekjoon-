#include <tuple>
#include <iostream>
using namespace std;

int main() {
	tuple<int, int, int> t1 = make_tuple(1, 2, 3);

	cout << get<0>(t1) << ' ';
	cout << get<1>(t1) << ' ';
	cout << get<2>(t1) << '\n';

	// get<>에서 <>안에 변수를 넣을 수 없음!
	/*for (int i = 0; i < 3; i++) {
		cout << get<i>(t1) << '\n';
	}*/

	return 0;
}