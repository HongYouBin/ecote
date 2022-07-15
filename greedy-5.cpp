#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, arr[100001], num[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	/*
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	int ans = n * (n - 1) / 2 - (n - m);
	cout << ans;
	*/
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	for (int i = 0; i < n; ++i)num[arr[i]]++;
	int ans = 0;
	for (int i = 1; i <= 10; ++i)
	{
		n -= num[i];
		ans += num[i] * n;
	}
	cout << ans;
}