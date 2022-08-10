#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, maxNum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<int> vt(n);
	vector<int> dp(n);
	maxNum = 1;

	for (int i = 0; i < n; ++i)cin >> vt[i];
	for (int i = 0; i < n;++i) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (vt[j] > vt[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				maxNum = max(dp[i], maxNum);
			}
		}
	}
	//sort(dp.begin(), dp.end());
	//cout << n - dp[n - 1] << '\n';
	cout << n - maxNum << '\n';

}