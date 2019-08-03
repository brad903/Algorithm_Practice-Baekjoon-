#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> a = { 1,2,3,4,5 };

	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	for (int x : a) {   // 단순히 a에 있는 것만 볼 것이면 이런 형태도 가능!
		cout << x << ' ';
	}
	cout << '\n';



	vector<pair<int, int>> b = { {1,2}, {3,4}, {5,6} };

	for (int i = 0; i < b.size(); i++) {
		cout << b[i].first + b[i].second << ' ';
	}
	cout << '\n';

	 
	for (auto &p : b) {    // 값 복사가 아닌 단순히 참조함
		cout << p.first + p.second << ' ';
	}
	cout << '\n';



	int sum = 0;
	for (auto x : { 1,2,3,4 })  // 변수나 배열로 선언해놓기 애매할 때 명시적으로 저렇게 사용가능
		sum += x;

	cout << "sum = " << sum << '\n';

	int c[] = { 1,2,3,4,5 };

	sum = 0;
	for (auto x : c)
		sum += x;

	cout << "sum = " << sum << '\n';



	const char cstr[] = "string";
	sum = 0;
	for (auto x : cstr) {  // 문자열 뒤에 NULL도 포함되기 때무에 sum은 6이 아니라 7이 됨
		sum += 1;
	}
	cout << "sum = " << sum << '\n';

	string str = "string";
	sum = 0;
	for (auto x : str) {  // string을 이용하면 위와 달리 sum이 6으로 나옴
		sum += 1;
	}
	cout << "sum = " << sum << '\n';

	return 0;
}