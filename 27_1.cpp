#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ans;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> vt(n);
	for (int i = 0; i < n; ++i)cin >> vt[i];

	int start = 0, end = n - 1, first, second;
	bool flag = false;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (vt[mid] == x && (mid == 0 || vt[mid - 1] != x)) {
			flag = true;
			first = mid;
			break;
		}
		else if (vt[mid] >= x) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	start = 0;
	end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (vt[mid] == x && (mid == n-1 || vt[mid + 1] != x)) {
			second = mid;
			break;
		}
		else if (vt[mid] > x) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	if (flag) cout << second - first + 1 << '\n';
	else cout << -1 << '\n';
}