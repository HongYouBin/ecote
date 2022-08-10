#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m, t[20], p[20], dp[20], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i <n; ++i) cin >> t[i] >> p[i];
	for (int i = n - 1; 0 <= i; --i) {
		if (n < i + t[i]) {
			dp[i] = ans;
			continue;
		}
		dp[i] = max(dp[i + t[i]] + p[i], ans);
		ans = dp[i];
	}
	cout << ans << '\n';
}