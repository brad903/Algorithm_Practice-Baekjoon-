#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> a = { 3,1,2 };
	sort(a.begin(), a.end()); // 정렬을 하지 않으면 3 1 2, 3 2 1 경우 밖에 안나옴

	do {
		for (int x : a) {
			cout << x << ' ';
		}
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));  // 사전 순으로 다음에 오는 순열을 만듬

	return 0;
}