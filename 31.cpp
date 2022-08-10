#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int t, n, m, arr[25][25], dp[25][25], ans;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j];
				dp[i][j] = 0;
				ans = 0;
			}
		}

		for (int i = 0; i < n; ++i) {
			dp[i][0] = arr[i][0];
		}

		for (int i = 1; i < m; ++i) {
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + arr[0][i];
			for (int j = 1; j < n - 1; ++j) {
				dp[j][i] = max({ dp[j - 1][i - 1], dp[j][i - 1], dp[j + 1][i - 1] }) + arr[j][i];
			}
			dp[n - 1][i] = max({ dp[n - 2][i - 1], dp[n - 1][i - 1] }) + arr[n - 1][i];
		}

		for (int i = 0; i < n; ++i) {
			ans = max(ans, dp[i][m - 1]);
		}
		cout << ans << '\n';
	}
}