#include <iostream>
#include <functional>
using namespace std;

int sum(int x, int y) {
	return x + y;
}

void main() {
	cout << sum(3, 5) << "\n";

	cout << [](int x, int y) {   // 이렇게 이름없이 사용가능
		return x + y;
	}(2, 4) << '\n';

	auto sum2 = [](int x, int y) {
		return x + y;
	};

	cout << sum2(1, 4) << "\n";


	int x = 10;
	int y = 20;

	auto f = [&x, y]() {
		x += 10;      // x는 값을 참조한 것이기 때문에 증감 가능
		//y += 10;    // y는 값을 복사한 것이기 때문에 증감하지 못함
	};

	cout << "x = " << x << ", y = " << y << "\n";
	f();
	cout << "x = " << x << ", y = " << y << "\n";
	f();
	cout << "x = " << x << ", y = " << y << "\n";


	/* 람다 함수의 변수타입 */
	function<void()> print = [] {
	};
	function<void(int)> print2 = [](int x) {
	};
	function<int(int, int)> print3 = [](int x, int y) {
		return x + y;
	};

	cout << print3(3, 3) << endl;
}