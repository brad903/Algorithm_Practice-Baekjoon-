#include <stack>
#include <list>
#include <iostream>
using namespace std;

int main() {
	stack<int> s1;                   // default는 deque형태의 스택

	stack<int, list<int>> s2;        // list와 같이 원하는 형태의 스택으로 설정가능

	deque<int> d = { 1,2,3,4,5 };
	stack<int> s3(d);

	cout << "-----------------------------------------------------------------\n";

	stack<int> s;
	
	for (int i = 1; i <= 5; i++) {
		s.push(i);
	}

	for (int i = 0; i < 2; i++) {
		cout << s.top() << '\n';
		s.pop();
	}

	cout << "size = " << s.size() << '\n';

	for (int i = 10; i >= 6; i--) {
		s.push(i);
	}

	cout << "size = " << s.size() << '\n';
	cout << "empty = " << s.empty() << '\n';

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';

	cout << "size = " << s.size() << '\n';
	cout << "empty = " << s.empty() << '\n';  // pop()으로 인해 비어있으므로 1 반환

	cout << "-----------------------------------------------------------------\n";

	stack<pair<int, int>> ss;
	ss.push(make_pair(1, 2));
	ss.push({ 3,4 });
	ss.emplace(5, 6);

	while (!ss.empty()) {
		auto pp = ss.top();
		cout << pp.first << ' ' << pp.second << '\n';
		ss.pop();
	}

	return 0;
}