#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1,4,1,2,4,2,4,2,3,4,4 };
	for (int i = 1; i <= 5; i++) {
		auto it = find(a.begin(), a.end(), i);
		cout << i << "의 위치: ";
		if (it == a.end()) {
			cout << "찾을 수 없음";
		}
		else {
			cout << (it-a.begin());   // 어떤 값이 여러 개의 있을 경우 제일 처음의 이터레이터를 반환
		}
		cout << '\n';
	}

	cout << "-----------------------------------------------------------------\n";

	auto even = find_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 0;
	});
	auto odd = find_if(a.begin(), a.end(), [](int x) {
		return x % 2 == 1;
	});

	cout << "첫 번째 짝수: " << (even - a.begin()) << '\n';
	cout << "첫 번째 홀수: " << (odd - a.begin()) << '\n';

	return 0;
}