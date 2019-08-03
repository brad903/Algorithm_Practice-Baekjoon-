#include <bitset>
#include <iostream>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	bitset<100> b1(A), b2(B);

	cout << "test";
	cout << (b1 & b2) << '\n';
	cout << (b1 | b2) << '\n';
	cout << (b1 ^ b2) << '\n';
	cout << (~b1) << '\n';
	cout << (~b2) << '\n';

	return 0;
}