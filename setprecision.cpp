#include <iomanip> // setprecision�� �������� ���
#include <iostream>
using namespace std;
int main() {
	double f = 3.14159265358979;
	cout << setprecision(5) << f << '\n';     // �Ҽ��� 5�ڸ����� �ݿø�
	cout << setprecision(8) << f << '\n';     // �Ҽ��� 8�ڸ����� �ݿø�
	cout << setprecision(10) << f << '\n';    // �Ҽ��� 10�ڸ����� �ݿø�

	cout << fixed << setprecision(5) << f << '\n';     // 5�ڸ����� ���
	cout << fixed << setprecision(8) << f << '\n';     // 8�ڸ����� ���
	cout << fixed << setprecision(10) << f << '\n';    // 10�ڸ����� ���
	return 0;
}