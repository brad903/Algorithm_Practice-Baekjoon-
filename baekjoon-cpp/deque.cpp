#include <deque>
#include <iostream>
using namespace std;

void print(deque<int> &a) {
	for (int &x : a) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	deque<int> d;

	d.push_back(1); print(d);
	d.push_front(2); print(d);
	d.push_back(3); print(d);
	d.pop_back(); print(d);
	d.pop_front(); print(d);

	return 0;
}