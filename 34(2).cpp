#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> arr(n);
	vector<int> dp;
	int ans = 0;
	dp.push_back(0);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] > dp.back()) {
			dp.push_back(arr[i]);
			ans++;
		}
		else {
			int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[idx] = arr[i];
		}
	}
	cout << ans;
}
