#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

int n, m, arr[55][55], visited[100], ans = 1e9;
vector<pii> house, chicken;

int calc(int x1, int x2, int y1, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int id, int cnt) {	
	if (cnt == m) {
		int totalDist = 0;
		for (int i = 0; i < house.size(); ++i) {
			int dist = 1e9;
			for (int j = 0; j < chicken.size(); ++j) {
				if (!visited[j]) continue;
				dist = min(dist, calc(house[i].first, chicken[j].first, house[i].second, chicken[j].second));
			}
			totalDist += dist;
		}
			ans = min(ans, totalDist);
			return;
	}

	if (id == chicken.size()) return;
	visited[id] = true;
	dfs(id + 1, cnt + 1);
	visited[id] = false;
	dfs(id + 1, cnt);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i, j });
			else if (arr[i][j] == 2)chicken.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << ans;
}