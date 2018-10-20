#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int D[31];

	D[0] = 1;
	D[1] = 0;
	D[2] = 3;
	for (int i = 3; i <= N; i++) {
		D[i] = 3 * D[i - 2];
		// 나도 모범답안처럼 좀 더 깔끔하게 쓸 수 있기를.. ㅠㅠ
		for (int j = 1; (i-2) - 2 * j >= 0; j++) {
			D[i] += 2*D[(i-2)-2*j];
		}
		// 모범답안의 좀 더 깔끔한 코드
		/*for (int j = i - 4; j >= 0; j -= 2) {
			D[i] += D[j] * 2;
		}*/
	}
	D[0] = 0;

	cout << D[N] << '\n';

	return 0;
}