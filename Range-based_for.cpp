#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> a = { 1,2,3,4,5 };

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	for (int x : a) {   // �ܼ��� a�� �ִ� �͸� �� ���̸� �̷� ���µ� ����!
		cout << x << ' ';
	}
	cout << '\n';



	vector<pair<int, int>> b = { {1,2}, {3,4}, {5,6} };

	for (int i = 0; i < b.size(); i++) {
		cout << b[i].first + b[i].second << ' ';
	}
	cout << '\n';

	 
	for (auto &p : b) {    // �� ���簡 �ƴ� �ܼ��� ������
		cout << p.first + p.second << ' ';
	}
	cout << '\n';



	int sum = 0;
	for (auto x : { 1,2,3,4 })  // ������ �迭�� �����س��� �ָ��� �� ��������� ������ ��밡��
		sum += x;

	cout << "sum = " << sum << '\n';

	int c[] = { 1,2,3,4,5 };

	sum = 0;
	for (auto x : c)
		sum += x;

	cout << "sum = " << sum << '\n';



	const char cstr[] = "string";
	sum = 0;
	for (auto x : cstr) {  // ���ڿ� �ڿ� NULL�� ���ԵǱ� ������ sum�� 6�� �ƴ϶� 7�� ��
		sum += 1;
	}
	cout << "sum = " << sum << '\n';

	string str = "string";
	sum = 0;
	for (auto x : str) {  // string�� �̿��ϸ� ���� �޸� sum�� 6���� ����
		sum += 1;
	}
	cout << "sum = " << sum << '\n';

	return 0;
}