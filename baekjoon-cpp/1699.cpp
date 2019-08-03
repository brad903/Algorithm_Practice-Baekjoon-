#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int D[100001];

	D[0] = 0;  // 인덱스 0인 부분 초기화 안해주면 쓰레기값이 쓰임
	D[1] = 1;
	for (int i = 1; i <= N; i++) {
		D[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (D[i] > D[i - j * j] + 1)
				D[i] = D[i - j * j] + 1;
		}
	}

	cout << D[N] << '\n';

	return 0;
}