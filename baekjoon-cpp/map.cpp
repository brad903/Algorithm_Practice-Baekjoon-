#include <map>
#include <iostream>
using namespace std;

int main(){
	map<int, int> d1;
	map<int, int> d2 = { {1,2},{3,4},{5,6} };

	cout << "d1.size() = " << d1.size() << '\n';
	cout << "d2.size() = " << d2.size() << '\n';

	d1[10] = 20;
	cout << "d1[10] = " << d1[10] << '\n';
	cout << "d2[1] = " << d2[1] << '\n';
	cout << "d2[2] = " << d2[2] << '\n';
	cout << "d2[3] = " << d2[3] << '\n';
	cout << "d2[4] = " << d2[4] << '\n';
	cout << "d2[5] = " << d2[5] << '\n';

	cout << "-----------------------------------------------------------------\n";

	map<int, int> d3;
	map<int, int> d4;

	for (int i = 1; i <= 9; i += 2) {
		d3[i] = i * i;
		d4[i] = i * i;
	}

	cout << "d3.size() = " << d3.size() << '\n';
	cout << "d4.size() = " << d4.size() << '\n';

	for (int i = 1; i <= 10; i++) {
		if (d1[i])            // ���� �κ� ���� ��������
			cout << i << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= 10; i++) {
		if (d2.count(i))       // ���� ������ �Ǵ�, ���� �������� ����
			cout << i << ' ';
	}
	cout << '\n';

	cout << "d3.size() = " << d3.size() << '\n';
	cout << "d4.size() = " << d4.size() << '\n';

	for (int i = 0; i < d3.size(); i++)
		cout << d3[i] << ' ';
	cout << '\n';

	cout << "-----------------------------------------------------------------\n";

	map<int, int> d = { {1,2},{3,4},{5,6} };
	for (auto it = d.begin(); it != d.end(); ++it)  // ���ͷ����͸� ���� pairó�� ���� ����
		cout << it->first << ' ' << it->second << '\n';

	for (auto p : d)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}