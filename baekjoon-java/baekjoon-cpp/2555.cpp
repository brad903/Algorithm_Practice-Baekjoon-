#include <iostream>
using namespace std;

// 람다를 이용한 풀이
// 풀이보다 백준님의 생일 찾기가 더 어려움 ㅋㅋ
int main() {
	auto print = [] {
		cout << "10/14" << "\n";
	};
	print();
	return 0;
}