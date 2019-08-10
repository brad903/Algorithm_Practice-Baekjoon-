#include <queue>
#include <iostream>
#include <functional>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp == 0) {
			if (q.empty()) cout << '0' << '\n';
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(temp);
		}
	}

	return 0;
}