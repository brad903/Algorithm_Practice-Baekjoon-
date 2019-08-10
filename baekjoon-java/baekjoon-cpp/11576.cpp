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
	
	// 진법에 맞게 출력시키기 위해 벡터에 저장
	vector<int> ans;

	// 0일 경우 예외처리
	if (num == 0) ans.push_back(0);
	else {
		while (num > 0) {
			int remain = (num % B);
			ans.push_back(remain);
			num = num / B;
		}
	}

	reverse(ans.begin(), ans.end());

	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}