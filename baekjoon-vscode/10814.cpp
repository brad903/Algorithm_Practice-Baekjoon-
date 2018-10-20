#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Person {
	int age;
	string name;
	int join;
};

bool emp(const Person &a, const Person &b) {
	if (a.age < b.age) return true;
	else if (a.age == b.age) return a.join < b.join;
	else return false;
}

int main() {
	int n;
	cin >> n;

	vector<Person> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
		v[i].join = i;  // 가입한 순으로 입력
	}

	/*sort(v.begin(), v.end(), emp);*/
	sort(v.begin(), v.end(), [](Person a, Person b) {
		return (a.age < b.age) || (a.age == b.age && a.join < b.join);
	});

	for(int i=0; i<n; i++){
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}