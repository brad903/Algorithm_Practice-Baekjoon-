#include <iomanip> // setprecision을 쓰기위한 헤더
#include <iostream>
using namespace std;
int main() {
	double f = 3.14159265358979;
	cout << setprecision(5) << f << '\n';     // 소수점 5자리에서 반올림
	cout << setprecision(8) << f << '\n';     // 소수점 8자리에서 반올림
	cout << setprecision(10) << f << '\n';    // 소수점 10자리에서 반올림

	cout << fixed << setprecision(5) << f << '\n';     // 5자리까지 출력
	cout << fixed << setprecision(8) << f << '\n';     // 8자리까지 출력
	cout << fixed << setprecision(10) << f << '\n';    // 10자리까지 출력
	return 0;
}