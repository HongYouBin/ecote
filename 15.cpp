#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
using namespace std;

int n, m, k, x, visited[300005];
vector<int> vt[300005], ans;
queue<pii> que;

int main() {
	cin >> n >> m >> k >> x;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
	}
	que.push({ x, 0 });
	visited[x] = 1;
	while (!que.empty()) {
		int prevCity = que.front().first;
		int dist = que.front().second;
		que.pop();
		if (dist == k) {
			ans.push_back(prevCity);
			continue;
		}
		for (auto i : vt[prevCity]) {
			if (visited[i])continue;
			visited[i] = 1;
			que.push({ i, dist + 1 });
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i : ans) cout << i << '\n';
}