#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m, arr[100001], num[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int ans = 50000;

	cin >> s;
	for (int i = 1; i <= s.length()/2; i++)
	{
		string nxt, compressed, prev;
		prev = s.substr(0, i);
		int count = 1;
		for (int j = i; j < s.length(); j += i)
		{
			nxt = s.substr(j, i);
			if (nxt == prev) count++;
			else
			{
				compressed += count > 1 ? to_string(count) + prev : prev;
				prev = nxt;
				count = 1;
			}
		}
		compressed += count > 1 ? to_string(count) + prev : prev;
		ans = min(ans, (int)compressed.length());
	}
	cout << ans;
}