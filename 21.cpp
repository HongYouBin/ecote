#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int,int>
using namespace std;

int n, l, r, visited[55][55], arr[55][55], sum, cnt;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pii> q;

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}
	int day = -1;
	while (true) {
		day++;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) visited[i][j] = false;
		}
		int idx = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j]) continue;
				visited[i][j] = true;
				q.push({ i, j });
				vector<pii> vt;
				vt.push_back({ i, j });
				sum = 0;
				cnt = 0;
				idx++;
				while (!q.empty()) {
					int row = q.front().first;
					int col = q.front().second; q.pop();
					sum += arr[row][col];
					cnt++;
					for (int i = 0; i < 4; ++i) {
						int nxtRow = row + dx[i];
						int nxtCol = col + dy[i];
						int gap = abs(arr[row][col] - arr[nxtRow][nxtCol]);
						if (gap < l || r < gap || visited[nxtRow][nxtCol]) continue;
						if (nxtRow < 0 || n <= nxtRow || nxtCol < 0 || n <= nxtCol) continue;
						visited[nxtRow][nxtCol] = true;
						q.push({ nxtRow, nxtCol });
						vt.push_back({ nxtRow, nxtCol });
					}
				}
				for (int i = 0; i < vt.size(); ++i) {
					arr[vt[i].first][vt[i].second] = sum / cnt;
				}
			}
		}
		if (idx == n * n) break;
	}
	cout << day << '\n';
}