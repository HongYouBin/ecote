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

int n, m, arr[100005], ans;
vector<pii> xVt, yVt, zVt;

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

	cin >> n;
	for (int i = 1; i <= n; ++i) arr[i] = i;

	int x, y, z;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> z;
		xVt.push_back({ x, i });
		yVt.push_back({ y, i });
		zVt.push_back({ z, i });
	}
	sort(xVt.begin(), xVt.end());
	sort(yVt.begin(), yVt.end());
	sort(zVt.begin(), zVt.end());

	vector<pip> edge;
	for (int i = 0; i < n - 1; ++i) {
		edge.push_back({ xVt[i + 1].first - xVt[i].first, {xVt[i + 1].second, xVt[i].second} });
		edge.push_back({ yVt[i + 1].first - yVt[i].first, {yVt[i + 1].second, yVt[i].second} });
		edge.push_back({ zVt[i + 1].first - zVt[i].first, {zVt[i + 1].second, zVt[i].second} });
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); ++i) {
		int fNode = edge[i].second.first;
		int sNode = edge[i].second.second;
		int cst = edge[i].first;
		if (findUnion(fNode) == findUnion(sNode)) continue;
		mergeUnion(fNode, sNode);
		ans += cst;
	}
	cout << ans << '\n';
}