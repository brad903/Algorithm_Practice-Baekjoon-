#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int A, B, m;
	cin >> A >> B;
	cin >> m;

	vector<int> D(m);

	for (int i = 0; i < m; i++) {
		cin >> D[i];
	}

	int num = 0;
	for (int i = 0; i < m; i++) {
		num = num * A + D[i];
	}

	string ans;

	while (num > 0) {
		char remain = (num % B) + '0';
		ans += remain;
		num = num / B;
	}

	reverse(ans.begin(), ans.end());

	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}