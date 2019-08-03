#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> b) {
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	vector<int> a = { 0,1,2,3,4,5 };
	rotate(a.begin(), a.begin() + 2, a.end());
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << "-------------------------------------------------------------\n";

	vector<int> b = { 0,1,2,3,4,5 };
	int n = b.size();
	for (int i = 0; i < n; i++) {
		//rotate(b.begin(), b.begin() + (n - 1), b.end());  // ���� �� ���Ҹ� �� ó�����θ� ������
		rotate(b.rbegin(), b.rbegin()+1, b.rend());  // b.rbegin()+1�� ���� �� ���Ҹ� ����Ű�� �Ϳ� ����!!
		print(b);
	}
	

	return 0;
}