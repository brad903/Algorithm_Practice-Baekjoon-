#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> a = { 1,5,6,7,10,20 };

	for (int i = 1; i <= 10; i++) {
		cout << i << ": ";
		cout << binary_search(a.begin(), a.end(), i) << '\n';
	}

	return 0;
}