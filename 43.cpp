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

int n, m, arr[200005];

int findUnion(int num) {
	if (arr[num] != num) {
		arr[num] = findUnion(arr[num]);
	}
	return arr[num];
}

void mergeUnion(int a, int b) {
	a = findUnion(a);
	b = findUnion(b);
	if (a > b) arr[a] = b;
	else arr[b] = a;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)arr[i] = i;

	vector<pip> vt(m);
	int x, y, z, sum = 0, krus = 0;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		vt.push_back({ z, {x, y} });
		sum += z;
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); ++i) {
		int firHo = vt[i].second.first;
		int secHo = vt[i].second.second;
		int cst = vt[i].first;
		if (findUnion(firHo) == findUnion(secHo)) continue;
		mergeUnion(firHo, secHo);
		krus += cst;
	}
	cout << sum - krus << '\n';
}