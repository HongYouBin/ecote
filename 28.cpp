#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, x, ans = -1;
	cin >> n;

	vector<int> vt(n);
	for (int i = 0; i < n; ++i) cin >> vt[i];

	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (vt[mid] == mid) {
			ans = mid;
			break;
		}
		else if (vt[mid] < mid) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans << '\n';
}