#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	string word;
	cin >> word;

	vector<int> v;

	for (int i = 'a'; i <= 'z'; i++) {
		int temp = 0;
		temp = count(word.begin(), word.end(), i);
		v.push_back(temp);
	}
	
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	return 0;
}
