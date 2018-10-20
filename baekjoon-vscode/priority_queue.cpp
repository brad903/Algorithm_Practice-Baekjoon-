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
		cout << -q2.top() << ' ';     // -�� ���̸� ���� ���� ���� ���� Ŀ���ٴ� ���� ����
		q2.pop();
	}
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	vector<int> c = { 5,2,4,1,3 };

	// �ι�° ���ڴ� priority_queue ���� container�� �������� �� ������
	// ����° ���ڴ� ������ ��� �Ұ��� ����
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
		cout << "top = " << q.top() << '\n';  // ť �ȿ� �ִ� ���� ���� ū �� ���
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';
	
	while (!q.empty()) {
		cout << "top = " << q.top() << '\n';  // ū �� ������� ���
		q.pop();
	}

	cout << "size = " << q.size() << '\n';
	cout << "empty = " << q.empty() << '\n';

	return 0;
}