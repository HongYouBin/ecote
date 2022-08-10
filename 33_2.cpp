#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int n, t[15], p[15], ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> t[i] >> p[i];

	for (int i = 1; i <= n; ++i) {
		vector<int> vt(n);
		fill(vt.end() - i, vt.end(), 1);
		
		do {
			int nxtDay = 0;
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				if (!vt[j] || j < nxtDay) continue;
				nxtDay = t[j] + j;
				if (n - 1 < nxtDay - 1) break;
				sum += p[j];
			}
			ans = max(ans, sum);
		} while (next_permutation(vt.begin(), vt.end()));
	}
	cout << ans << '\n';
}
