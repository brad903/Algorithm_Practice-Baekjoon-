#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	auto last = unique(a.begin(), a.end());  // unique는 중복을 제거한 후의 end 이터레이터를 반환
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
	for (auto it = a.begin(); it != last; ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	cout << "-------------------------------------------------------------\n";

	vector<int> b = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };

	auto last2 = unique(b.begin(), b.end());
	b.erase(last2, b.end()); // last부터 end가지 불필요한 부분 제거
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << "-------------------------------------------------------------\n";
	// 이번엔 c를 미리 정렬한 후 unique함수를 써보겠습니다!
	vector<int> c = { 1,1,2,2,2,3,1,1,1,2,2,2,2 };

	sort(c.begin(), c.end());  // 오름차순 정렬
	auto last3 = unique(c.begin(), c.end());
	c.erase(last3, c.end()); // last부터 end가지 불필요한 부분 제거
	for (int x : c) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}