#include <queue>
#include <list>
#include <iostream>
using namespace std;

int main() {
	queue<int> q1;

	queue<int, list<int>> q2;

	deque<int> d = { 1,2,3,4,5 };
	queue<int> q3(d);

	cout << "-----------------------------------------------------------------\n";

	queue<int> q;

	for (int i = 1; i <= 5; i++) {
		q.push(i);
	}

	for (int i = 0; i < 2; i++) {
		cout << q.front() << ' ' << q.back() << '\n';
		q.pop();
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';

	for (int i = 6; i <= 10; i++) {
		q.push(i);
		cout << "back = " << q.back() << '\n';
	}

	while (!q.empty()) {
		cout << q.front() << ' ' << q.back() << '\n';
		q.pop();
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';

	cout << "-----------------------------------------------------------------\n";

	queue<pair<int, int>> qq;
	qq.push(make_pair(1, 2));
	qq.push({ 3,4 });
	qq.emplace(5, 6);

	while (!qq.empty()) {
		auto p = qq.front();
		cout << p.first << ' ' << p.second << '\n';
		qq.pop();
	}

	return 0;
}