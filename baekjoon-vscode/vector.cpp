#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print(vector<int> &a) {
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	vector<int> v1;
	vector<int> v2(10);  // 길이10
	vector<int> v3(15, 1);  // 길이 15, 초기값 1로 모두 초기화
	vector<int> v4 = { 1,2,3,4,5 };

	vector<int> a = { 1,2,3,4,5 };
	a.push_back(6);  // [1,2,3,4,5,6]
	a.push_back(7);  // [1,2,3,4,5,6,7]

	a.pop_back();  // [1,2,3,4,5,6]
	a.pop_back();  // [1,2,3,4,5]
	a.pop_back();  // [1,2,3,4]

	a.clear();  // []

	a.resize(5); // [0,0,0,0,0]

	a.clear();  // []

	a.push_back(1);  // [1]
	a.push_back(2);  // [1,2]

	a.resize(5);  // [1,2,0,0,0]
	a.resize(3);  // [1,2,0]
	a.clear();  // []


	vector<int> c = { 1,2,3,4 };
	cout << "size = " << c.size() << '\n';

	c.push_back(5);
	cout << "size = " << c.size() << '\n';
	cout << "empty = " << c.empty() << '\n';

	c.clear();
	cout << "size = " << c.size() << '\n';
	cout << "empty = " << c.empty() << '\n';


	vector<int> b = { 1,2,3 };
	cout << "front = " << b.front() << '\n';
	cout << "a[1] = " << b[1] << '\n';
	cout << "back = " << b.back() << '\n';

	b.push_back(4);

	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';


	vector<int> d = { 1,2,3,4,5 };

	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';

	for (int &x : d)
		cout << x << ' ';
	cout << '\n';


	vector<int> e = { 1,2,3,4,5 };

	// end()는 제일 마지막 원소의 다음을 가리킴
	for (vector<int>::iterator it = e.begin(); it != e.end(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	for (auto it = e.begin(); it != e.end(); ++it) {
		cout << "e[" << it - e.begin() << "] = " << *it << '\n';
	}


	vector<pair<int, int>> f;
	f.emplace_back(1, 2);
	f.push_back({ 3,4 });
	f.push_back(make_pair(5, 6));

	for (auto &x : f) {
		cout << x.first << ' ' << x.second << '\n';
	}

	for (auto it = f.begin(); it != f.end(); ++it) {  
		cout << it->first << ' ' << (*it).second << '\n';   // it을 포인터와 같은 개념으로 생각! 
	}


	vector<int> g = { 1,2,3 };
	print(g);  // print함수 main함수 위에 정의되어 있음

	auto it = g.begin();
	g.insert(it, 4); print(g);

	it = g.begin() + 1;
	g.insert(it, 5, 0); print(g);

	it = g.begin() + 2;
	vector<int> h = { 10, 20 };
	g.insert(it, h.begin(), h.end()); print(g);

	return 0;
}