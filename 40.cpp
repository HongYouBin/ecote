#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

#define inf 1e9
#define pip pair<int, pair<int, int>>
#define pii pair<int, int>
using namespace std;

int n, m, arr[20005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> vt[20005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	fill(arr, arr + n + 1, inf);

	int a, b, maxDist = 1;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int dist = pq.top().first, curNum = pq.top().second;
		pq.pop();
		if (arr[curNum] < dist) continue;
		arr[curNum] = dist;
		maxDist = max(dist, maxDist);
		for (int& nxtNum : vt[curNum]) {
			pq.push({ dist + 1, nxtNum });
		}
	}
	int ans = inf, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (maxDist != arr[i]) continue;
		ans = min(ans, i);
		cnt++;
	}
	cout << ans << ' ' << maxDist << ' ' << cnt << '\n';
}