#include <set>
#include <iostream>
using namespace std;

// �ð� �ʰ� �߻�.. 
// �̺� Ž�� �����ؼ� �� �� �����ϰ� �ذ��ϴ� ������..

int main() {
	int n;
	scanf("%d", &n);

	multiset<int> s;  // multiset�� �̿��Ͽ� ���� �� ���� �ߺ� ���

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		s.insert(temp);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", s.count(temp));
	}
	printf("\n");

	return 0;
}