#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define inf 1e9
#define pii pair<int, int>
using namespace std;

int n, arr[25][25], dist[25][25], sSize = 2, ans;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = inf;
		}
	}
}

void bfs(int row, int col) {
	init();
	dist[row][col] = 0;
	queue<pii> q;
	q.push({ row, col });
	while (!q.empty()) {
		auto pos = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i], ny = pos.second + dy[i];
			if (nx < 0 || n <= nx || ny<0 || n <= ny || arr[nx][ny]>sSize || dist[nx][ny] != inf) continue;
			dist[nx][ny] = dist[pos.first][pos.second] + 1;
			q.push({ nx, ny });
		}
	}
}

void find(int row, int col) {
	arr[row][col] = 0;
	int eat = 0;
	pii position = { row, col };
	while (true) {
		int minDst = inf;
		bfs(position.first, position.second);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] == inf) continue;
				if (dist[i][j] < minDst && 0 < arr[i][j] && arr[i][j]<sSize) {
					position = { i,j };
					minDst = dist[i][j];
				}
			}
		}
		if (minDst == inf) {
			break;
		}
		else {
			eat++;
			arr[position.first][position.second] = 0;
			ans += dist[position.first][position.second];
		}
		if (eat >= sSize) {
			eat = 0;
			sSize++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	pii start;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) start = { i,j };
		}
	}
	find(start.first, start.second);
}