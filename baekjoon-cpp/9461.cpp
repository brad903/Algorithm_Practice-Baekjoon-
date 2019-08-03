#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	long long P[101];
	P[0] = 0;
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;
	P[9] = 7;
	P[10] = 9;

	// 아래와 같이 초기화도 가능
	//long long P[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

	//for (int i = 6; i <= 100; i++) {
	//	P[i] = P[i - 1] + P[i - 5];
	//}

	// 길이를 이용하는 경우
	for (int i = 4; i <= 100; i++) {
		P[i] = P[i - 2] + P[i - 3];
	}

	for (int i = 0; i < T; i++) {
		int temp;
		cin >> temp;
		cout << P[temp] << '\n';
	}

	return 0;
}