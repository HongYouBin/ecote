// 이것이 코딩테스트다 p314 greedy 4번
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, arr[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	sort(arr, arr + n);
	int ans = 1;
	for (int i = 0; i < n; ++i)
	{
		if (ans < arr[i])break;
		ans += arr[i];
	}
	cout << ans;
}