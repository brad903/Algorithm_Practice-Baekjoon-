#include <iostream>
#include <cstdio>
using namespace std;

// 시간 초과 발생
//int memo[45];
//int Fibonacci(int n) {
//	if (n <= 1) return n;
//	else {
//		if (memo[n] > 0) return memo[n];
//		else {
//			return Fibonacci(n - 1) + Fibonacci(n - 2);
//		}
//	}
//}

// 시간 초과 발생
//int Fibonacci(int n) {
//	if (n <= 1) return n;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}

int main() {
	int n;
	scanf("%d", &n);

	long long memo[90] = { 0, };
	memo[0] = 0, memo[1] = 1;

	for (int i = 2; i <= n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	printf("%lld\n", memo[n]);

	return 0;
}
