#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int n, m, arr[10][10];
vector<pii> emptyRoom, virus, wall;
queue<pii> q;

int dx[4] = { 0,0,1, -1 };
int dy[4] = { 1,-1,0,0 };

int bfs() {
	vector<pii> memo;
	int cnt = 0;
	for (int i = 0; i < virus.size(); ++i) {
		auto position = virus[i];
		cnt++;
		q.push(position);
		while (!q.empty()) {
			position = q.front(); q.pop();
			for (int j = 0; j < 4; ++j) {
				int nxtX = position.first + dx[j];
				int nxtY = position.second + dy[j];
				if (nxtX < 0 || n <= nxtX || nxtY < 0 || m <= nxtY || arr[nxtX][nxtY] != 0)continue;
				arr[nxtX][nxtY] = 2;
				memo.push_back({ nxtX, nxtY });
				cnt++;
				q.push({ nxtX, nxtY });
			}
		}
	}

	for (int i = 0; i < memo.size(); ++i) arr[memo[i].first][memo[i].second] = 0;
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) emptyRoom.push_back({ i, j });
			else if (arr[i][j] == 1) wall.push_back({ i, j });
			else virus.push_back({ i,j });
		}
	}
	vector<int> bin(emptyRoom.size());
	fill(bin.end() - 3, bin.end(), 1);
	int area = 100;
	do {
		vector<pii> memo;
		for (int i = 0; i < bin.size(); ++i) {
			if (!bin[i])continue;
			memo.push_back(emptyRoom[i]);
			arr[emptyRoom[i].first][emptyRoom[i].second] = 1;
		}
		area = min(area, bfs());
		for (int i = 0; i < memo.size(); ++i) {
			arr[memo[i].first][memo[i].second] = 0;
		}
	} while (next_permutation(bin.begin(), bin.end()));
	int ans = n * m - wall.size() - 3 - area;
	cout << ans << '\n';
}