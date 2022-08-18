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

int n, m, arr[505][505], unionArr[505];

int findUnion(int num) {
	if (unionArr[num] != num) {
		unionArr[num] = findUnion(unionArr[num]);
	}
	return unionArr[num];
}

void mergeUnion(int a, int b) {
	a = findUnion(a);
	b = findUnion(b);
	if (a > b) unionArr[a] = b;
	else unionArr[b] = a;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		unionArr[i] = i;
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}
	vector<int> vt(m);
	for (int i = 0; i < m; ++i)cin >> vt[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!arr[i][j] || findUnion(i) == findUnion(j)) continue;
			mergeUnion(i, j);
		}
	}
	int num = unionArr[vt[0]];
	for (int& i : vt) {
		if (num != unionArr[i]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}