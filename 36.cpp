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

int n, arr[5001][5001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= a.size(); ++i)arr[i][0] = i;
	for (int j = 0; j <= b.size(); ++j)arr[0][j] = j;
	for (int i = 1; i <= a.size(); ++i) {
		for (int j = 1; j <= b.size(); ++j) {
			if (a[i] == b[j]) arr[i][j] = arr[i - 1][j - 1];
			else arr[i][j] = min({ arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1] }) + 1;
		}
	}
	cout << arr[a.size()][b.size()] << '\n';
}