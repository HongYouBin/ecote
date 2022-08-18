#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

#define inf 1e9
#define pip pair<int, pair<int, int>>
using namespace std;

int n, m, t, arr[130][130], memo[130][130], dRow[4] = { 0, 0, 1, -1 }, dCol[4] = { 1, -1, 0, 0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		priority_queue < pip, vector<pip>, greater<pip>> pq;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				memo[i][j] = inf;
			}
		}
		int cst = arr[0][0], row = 0, col = 0;
		pq.push({ cst, {row, col} });
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			int cst = cur.first, row = cur.second.first, col = cur.second.second;
			if (memo[row][col] < cst)continue;
			memo[row][col] = cst;

			for (int i = 0; i < 4; ++i) {
				int nxtRow = row + dRow[i], nxtCol = col + dCol[i];
				if (nxtRow < 0 || n <= nxtRow || nxtCol < 0 || n <= nxtCol) continue;
				int nxtCst = cst + arr[nxtRow][nxtCol];
				pq.push({ nxtCst,{nxtRow, nxtCol} });
			}
		}
		cout << memo[n - 1][n - 1] << '\n';
	}
}