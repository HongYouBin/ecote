#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define inf 1e9
#define pii pair<int, int>
#define pip pair<int, pair<int, int>>
using namespace std;

int cnt, n, m, k, ans, mTime, arr[25][25], order[401][4][4], sharkDir[402], dead[402], dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
pii smell[25][25], sharkPos[402];

void chk() {
	int tmpArr[25][25];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) tmpArr[i][j] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		if (dead[i]) continue;
		if (tmpArr[sharkPos[i].first][sharkPos[i].second]) {
			dead[i] = 1;
			cnt--;
		}
		tmpArr[sharkPos[i].first][sharkPos[i].second] = i;
	}
}

void move(int num) {
	int x = sharkPos[num].first;
	int y = sharkPos[num].second;
	int dir = sharkDir[num];
	vector<pip> empPos;
	vector<pip> smPos;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
		if (smell[nx][ny].first == 0) empPos.push_back({ i + 1, { nx, ny } });
		else if (smell[nx][ny].first != 0 && smell[nx][ny].second == num) smPos.push_back({ i + 1, { nx, ny } });
	}
	
	int nx, ny, nxtDir, idx = inf;
	
	if (!empPos.empty()) {
		for (int i = 0; i < empPos.size(); ++i) {
			for (int j = 0; j < 4; ++j) {
				if (order[num][dir - 1][j] == empPos[i].first && j < idx) {
					idx = j;
					nxtDir = empPos[i].first;
					nx = empPos[i].second.first;
					ny = empPos[i].second.second;
				}
			}
		}
	}
	else  {
		for (int i = 0; i < smPos.size(); ++i) {
			for (int j = 0; j < 4; ++j) {
				if (order[num][dir - 1][j] == smPos[i].first && j < idx) {
					idx = j;
					nxtDir = smPos[i].first;
					nx = smPos[i].second.first;
					ny = smPos[i].second.second;
				}
			}
		}
	}
	sharkPos[num].first = nx;
	sharkPos[num].second = ny;
	sharkDir[num] = nxtDir;
}

void solv() {
	while (true) {
		mTime++;
		if (mTime > 1000) {
			ans = -1;
			return;
		}
		
		for (int i = 1; i <= m; ++i) {
			if (dead[i]) continue;
			pii curPos = sharkPos[i];
			smell[curPos.first][curPos.second].first = k;
			smell[curPos.first][curPos.second].second = i;
		}
		
		for (int i = 1; i <= m; ++i) {
			if (dead[i]) continue;
			move(i);
		}
		chk();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (smell[i][j].first > 0)smell[i][j].first--;
			}
		}
		if (cnt == 1) {
			ans = mTime;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	cnt = m;
	int inp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> inp;
			if (inp) sharkPos[inp] = { i,j };
		}
	}
	for (int i = 1; i <= m; ++i) cin >> sharkDir[i];
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int t = 0; t < 4; ++t) {
				cin >> order[i][j][t];
			}
		}
	}

	solv();
	cout << ans << '\n';
}