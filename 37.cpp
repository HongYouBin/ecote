#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

#define inf 1e9
using namespace std;

int n, m, arr[105][105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = inf;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (arr[i][j] == inf) cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}