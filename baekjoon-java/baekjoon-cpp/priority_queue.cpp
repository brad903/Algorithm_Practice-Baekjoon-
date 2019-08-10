#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

int main() {
	vector<int> a = { 5,2,4,1,3 };

	priority_queue<int> q1;

	for (int x : a) {
		q1.push(x);
	}

	while (!q1.empty()) {
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	vector<int> b = { 5,2,4,1,3 };

	priority_queue<int> q2;
	for (int x : b) {
		q2.push(-x);
	}

	while (!q2.empty()) {
		cout << -q2.top() << ' ';     // -를 붙이면 제일 작은 수가 제일 커진다는 점을 착안
		q2.pop();
	}
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	vector<int> c = { 5,2,4,1,3 };

	// 두번째 인자는 priority_queue 내부 container는 무엇으로 할 것인지
	// 세번째 인자는 정렬을 어떻게 할건지 결정
	priority_queue<int, vector<int>, greater<int>> q3;
	for (int x : a) {
		q3.push(x);
	}
	while (!q3.empty()) {
		cout << q3.top() << ' ';
		q3.pop();
	}
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	priority_queue<int> q;

	for (int x : {2, 1, 4, 3, 5}) {
		cout << "x = " << x << ", ";
		q.push(x);
		cout << "top = " << q.top() << '\n';  // 큐 안에 있는 값중 제일 큰 값 출력
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';
	
	while (!q.empty()) {
		cout << "top = " << q.top() << '\n';  // 큰 수 순서대로 출력
		q.pop();
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';

	return 0;
}