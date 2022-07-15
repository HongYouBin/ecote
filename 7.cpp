#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, arr[100001], num[100001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s;
	int halfSize = s.size() / 2;
	int firstSum, secondSum;
	firstSum = secondSum = 0;
	for (int i = 0; i < halfSize; ++i) firstSum += s[i] - '0';
	for (int i = halfSize; i < s.size(); ++i) secondSum += s[i] - '0';
	if (firstSum == secondSum) cout << "LUCKY";
	else cout << "READY";
}