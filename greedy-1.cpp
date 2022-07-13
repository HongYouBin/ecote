// 이것이 코딩테스트다 p311
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	int num = 0;
	for (int i = 0; i < n; ++i) 
	{
		num++;
		if (arr[i] <= num)
		{
			ans++;
			num = 0;
		}
	}
	cout << ans;
}

