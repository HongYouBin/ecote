#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> vt(n);

	for (int i = 0; i < n; ++i)cin >> vt[i];
	int firstIndex = lower_bound(vt.begin(), vt.end(), x) - vt.begin();
	int secondIndex = upper_bound(vt.begin(), vt.end(), x) - vt.begin();

	/*
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	*/

	if (secondIndex - firstIndex) cout << secondIndex - firstIndex << '\n';
	else cout << -1 << '\n';
}