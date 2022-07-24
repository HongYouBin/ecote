#include <iostream>
#include <queue>

#define pii pair<int, int>
#define pip pair<pair<int, int>, pair<int, int>>
using namespace std;

int n, k, s, x, y, arr[210][210];
queue<pip> q;
vector < pair<int, pair<int, int>>> vt;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j]) vt.push_back({ arr[i][j], {i,j} });
		}
	}
	cin >> s >> x >> y;
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); ++i) {
		q.push({ {0, vt[i].first}, {vt[i].second.first, vt[i].second.second} });
	}
	while (!q.empty()) {
		int time = q.front().first.first;
		int vir = q.front().first.second;
		int curRow = q.front().second.first;
		int curCol = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nxtRow = curRow + dx[i];
			int nxtCol = curCol + dy[i];
			if (nxtRow < 0 || n <= nxtRow || nxtCol < 0 || n <= nxtCol || arr[nxtRow][nxtCol] != 0 || s <= time) continue;
			arr[nxtRow][nxtCol] = vir;
			q.push({ {time+1, vir}, {nxtRow, nxtCol} });
		}
	}
	cout << arr[x - 1][y - 1] << '\n';
}
