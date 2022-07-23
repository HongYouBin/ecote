#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int n, m, arr[10][10], ans;
vector<pii> emptyRoom, virus, wall;
queue<pii> q;
int tmpArr[10][10];

int dx[4] = { 0,0,1, -1 };
int dy[4] = { 1,-1,0,0 };

int count() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tmpArr[i][j] == 0)cnt++;
		}
	}
	return cnt;
}

void spreadViruse(int row, int col) {
	for (int i = 0; i < 4; ++i) {
		int nxtRow = row + dx[i];
		int nxtCol = col + dy[i];
		if (nxtRow < 0 || n <= nxtRow || nxtCol < 0 || m <= nxtCol || tmpArr[nxtRow][nxtCol] != 0) continue;
		tmpArr[nxtRow][nxtCol] = 2;
		spreadViruse(nxtRow, nxtCol);
	}
}

void dfs(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				tmpArr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (tmpArr[i][j] == 2) spreadViruse(i, j);
			}
		}
		ans = max(ans, count());
		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] != 0) continue;
			arr[i][j] = 1;
			dfs(cnt + 1);
			arr[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			/*if (arr[i][j] == 0) emptyRoom.push_back({ i, j });
			else if (arr[i][j] == 1) wall.push_back({ i, j });
			else virus.push_back({ i,j });*/
		}
	}
	dfs(0);
	cout << ans << '\n';
}