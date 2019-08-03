#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Person {
	int age;
	string name;
};

bool emp(const Person &a, const Person &b) {
	if (a.age < b.age) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;

	vector<Person> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
	}

	stable_sort(v.begin(), v.end(), emp);  // 만약 나이가 같을 때는 stable_sort 특성상 입력순으로 정렬됨!

	for (int i = 0; i<n; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}