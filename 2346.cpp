#include <iostream>
#include <list>
using namespace std;

int main() {
	int n;
	list<pair<int, int>> a;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back({ x,i });
	}

	auto it = a.begin();
	for (int i = 0; i < n - 1; i++) {
		cout << it->second << ' ';
		int step = it->first;
		if (step > 0) {
			auto temp = it;
			++temp;
			if (temp == a.end()) temp = a.begin();
			a.erase(it);
			for (int i = 1; i < step; i++) {
				++temp;
				if (temp == a.end()) temp = a.begin();
			}
			it = temp;
		}
		else if (step < 0) {
			step = -step;
			auto temp = it;

			// 백준 선생님 풀이
			/*if (temp == a.begin()) {
				temp = a.end();
			}
			--temp;
			a.erase(it);
			it = temp;
			for (int i = 1; i<step; i++) {
				if (it == a.begin()) {
					it = a.end();
				}
				--it;
			}*/

			// 내가 풀었지만 왜 틀렸는지 이해가 안되는 부분
			/*a.erase(it);
			for (int i = 0; i < step; i++) {
				if (temp == a.begin()) {
					temp = a.end();
					--temp;
				}
				else {
					--temp;
				}
			}
			it = temp;*/

			if (temp == a.begin()) temp = a.end();
			temp--;
			for (int i = 1; i < step; i++) {
				if (temp == a.begin()) temp = a.end();
				--temp;
			}
			it = temp;
		}
	}

	cout << a.front().second << '\n';

	return 0;
}

