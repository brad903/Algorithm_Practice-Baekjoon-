#include <list>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void print(list<int> &a) {
	for (auto &x : a) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	list<int> l = { 2,1,-5,4,-3,6,-7 }; 

	l.sort(); print(l);  // 오름차순

	l.sort(greater<int>()); print(l);  // 내림차순

	l.sort([](int &u, int &v) {  // 절대값 순으로
		return abs(u) < abs(v);
	});
	print(l);

	l.reverse(); print(l);  // 역순

	return 0;
}