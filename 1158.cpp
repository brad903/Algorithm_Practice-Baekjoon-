#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	queue<int> q;

	// 큐 안에 우선 수를 다 넣음
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	// 사람 제거
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m-1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front() << ">" << endl;
	q.pop();


	return 0;
}