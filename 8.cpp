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
	
	cin >> s;
	//vector<int> str, number;
	string str;
	int number = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9') number += s[i] - '0';
		else str.push_back(s[i]);
	}
	sort(str.begin(), str.end());
	if (number != 0)cout << str << number;
	else cout << str;
}