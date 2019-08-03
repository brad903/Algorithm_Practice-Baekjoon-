#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(7);
	a.push_back(13);
	a.push_back(50);
	
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << "\n";

	vector<int> b = { 1,3,7,13,50 };
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
	cout << "\n";

	struct Person {
		string name;
		int age;
	};

	set<int> s = { 1,2,3,4,5 };
	map<int, string> m = { {20, "a"}, {10, "hi"} };
	Person p = { "you", 20 };
	map<int, vector<pair<int, int>>> m2 = {    // 이와 같이 배열 선언하는 것처럼 다양하게 C++11부터 사용가능
		{10, {{1,2},{3,4}}},
	{20,{{5,6},{7,8},{9,10}}}
	};

	return 0;
}