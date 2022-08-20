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

int tc, n, m, a, b, arr[505][505], indegree[505];

void init() {
	for (int i = 1; i <= n; ++i) {
		indegree[i] = 0;
		for (int j = 1; j <= n; ++j) {
			arr[i][j] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		cin >> n;
		vector<int> t(n);
		for (int i = 0; i < n; ++i)cin >> t[i];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				arr[t[i]][t[j]] = 1;
				indegree[t[j]]++;
			}
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if (arr[a][b]) {
				arr[a][b] = 0;
				arr[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				arr[a][b] = 1;
				arr[b][a] = 0;
				indegree[b]++;
				indegree[a]--;
			}
		}


		int cnt = n;
		queue<int> q;
		vector<int> rank;
		for (int i = 1; i <= n; ++i) {
			if (!indegree[i]) q.push(i);
		}
		while (q.size() == 1) {
			cnt--;
			rank.push_back(q.front()); q.pop();
			for (int i = 1; i <= n; ++i) {
				if (!arr[rank.back()][i])continue;
				indegree[i]--;
				if (!indegree[i]) q.push(i);
			}
		}
		if (q.size() == 0 && cnt == 0) {
			for (int& i : rank) cout << i << ' ';
		}
		else if (q.size() > 1) cout << '?';
		else cout << "IMPOSSIBLE";
		cout << '\n';
	}
}