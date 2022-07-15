// 이것이 코딩테스트다 p312 greedy 2번
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, arr[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s;
	int zero = 0;
	int one = 0;
	char prevNum = s[0];
	if (prevNum == '0')zero++;
	else one++;
	for (int i = 1; i < s.size(); ++i)
	{
		if (prevNum == s[i])continue;
		if (s[i] == '1') one++;
		else zero++;
		prevNum = s[i];
	}
	cout << min(zero, one);
}

