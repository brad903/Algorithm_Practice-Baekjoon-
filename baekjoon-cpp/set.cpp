#include <set>
#include <iostream>
#include <functional>
using namespace std;

void print(set<int> &s, set<int>::iterator it) {
	if (it == s.end()) {
		cout << "end\n";
	}
	else {
		cout << *it << '\n';
	}
}

int main() {
	set<int> s1;
	set<int> s2 = { 1,2,3,4,5 };
	set<int> s3 = { 1,1,1,1,1,2,2,2,2,2,3,3,3,3 };

	cout << "s1.size() = " << s1.size() << '\n';
	cout << "s2.size() = " << s2.size() << '\n';
	cout << "s3.size() = " << s3.size() << '\n';

	set<int, greater<int>> s4;  // set는 기본적으로 오름차순으로 정렬됨. 내림차순으로 정렬되게 함

	set<int> s;
	s.insert(1); s.insert(3); s.insert(2);

	cout << "s.size() = " << s.size() << '\n';

	pair<set<int>::iterator, bool> result = s.insert(4);  // 반환값으로 pair(이터레이터, 성공여부) 반환
	cout << "result iterator = " << *result.first << '\n';
	cout << "result bool = " << result.second << '\n';

	auto result2 = s.insert(3);
	cout << "result2 iterator = " << *result2.first << '\n';
	cout << "result2 bool = " << result2.second << '\n';  // 중복값이 이미 있기 때문에 삽입 실패

	set<int> ss = { 1,2,3,4,5 };
	ss.erase(ss.begin());
	cout << "ss.size() = " << ss.size() << '\n';

	auto it = ss.begin();
	++it;
	cout << "*it = " << *it << '\n';
	it = ss.erase(it);
	cout << "*it = " << *it << '\n';
	cout << "ss.size() = " << ss.size() << '\n';

	set<int> sss = { 5,2,4,1,3,7,6 };

	for (auto it = sss.begin(); it != sss.end(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	for (auto x : sss) {
		cout << x << ' ';
	}
	cout << '\n';

	set<int> ssss = { 7,5,3,1 };

	auto it2 = ssss.find(1);
	print(ssss, it2);

	it2 = ssss.find(2);
	print(ssss, it2);

	it2 = ssss.find(3);
	print(ssss, it2);

	it2 = ssss.find(4);
	print(ssss, it2);

	for (int i = 1; i <= 9; i++) {
		cout << "ssss.count(" << i << ") = " << ssss.count(i) << '\n';
	}

	return 0;
}

