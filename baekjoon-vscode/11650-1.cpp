#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 구조체와 연산자 오버로딩을 이용한 방법
struct Point {
	int x, y;
	bool operator < (const Point &v) const {
		if (x < v.x) {
			return true;
		}
		else if (x == v.x) {
			return y < v.y;
		}
		else {
			return false;
		}
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}

	return 0;
}