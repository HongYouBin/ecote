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

int g, p, arr[100005], ans;

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
	
	cin >> g >> p;

	for (int i = 0; i <= g; ++i) arr[i] = i;

	int inp;
	for (int i = 0; i < p; ++i) {
		cin >> inp;
		if (0 == findUnion(inp)) break;
		mergeUnion(inp, findUnion(inp) - 1);
		ans++;
	}
	cout << ans << '\n';
}