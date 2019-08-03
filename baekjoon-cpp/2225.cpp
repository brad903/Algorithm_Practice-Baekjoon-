#include <iostream>
using namespace std;
// 전역 변수로 하면 0으로 초기화되므로 이용
long long D[201][201];
long long mod = 1000000000;

int main() {
	int N, K;
	cin >> N >> K;

	D[0][0] = 1LL;  // long long 타입의 1
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				D[i][j] += D[i - 1][j - k];
				D[i][j] %= mod;
			}
		}
	}

	cout << D[K][N] << '\n';


	return 0;
}