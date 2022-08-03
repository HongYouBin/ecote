#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, c, ans = -1;
	cin >> n >> c;
	vector<int> vt(n);
	for (int i = 0; i < n; ++i) cin >> vt[i];
	sort(vt.begin(), vt.end());
	int end = vt[n - 1] - vt[0];
	int start = 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		int minNum = mid;
		int tmpC = c - 1;
		int setIdx = 0;
		for (int i = 1; i < n; ++i) {
			if (vt[i] - vt[setIdx] < mid) continue;
			if (!tmpC) break;
			tmpC--;
			setIdx = i;
		}

		if (tmpC) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			ans = mid;
		}
	}
	cout << ans << '\n';
}