#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

int n, m, arr[55][55];
vector<pii> house, chicken;

int check(vector<pii> candidate) {
	int totalDist = 0;
	for (int i = 0; i < house.size(); ++i) {
		int dist = 1e9;
		for (int j = 0; j < candidate.size(); ++j) {
			int r = house[i].first;
			int c = house[i].second;
			int sum = abs(r - candidate[j].first) + abs(c - candidate[j].second);
			dist = min(dist, sum);
		}
		totalDist += dist;
	}
	return totalDist;
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
	vector<bool> bin(chicken.size());
	//for (int i = m; i < chicken.size(); ++i) bin[i] = true;
	fill(bin.end() - m, bin.end(), true);
	int ans = 1e9;

	do {
		vector<pii> candidate;
		for (int i = 0; i < chicken.size(); ++i){
			if (bin[i]) candidate.push_back({ chicken[i].first, chicken[i].second });
		}
		ans = min(ans, check(candidate));
	} while (next_permutation(bin.begin(), bin.end()));
	cout << ans;
}