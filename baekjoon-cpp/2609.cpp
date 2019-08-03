#include <iostream>
#include <algorithm>
using namespace std;

// 유클리드 호제법 이용
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	else return gcd(b, a%b);
//}

// 재귀함수 사용하지 않은 유클리드 호제법
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	int a, b;
	cin >> a >> b;

	// 기본적인 문제풀이
	int g = 1;
	/*for (int i = 2; i <= min(a, b); i++) {
		if (a%i == 0 && b%i == 0){
			g = i;
		}
	}*/

	g = gcd(a, b);

	int l = g * (a / g) * (b / g);

	cout << g << '\n';
	cout << l << '\n';

	return 0;
}