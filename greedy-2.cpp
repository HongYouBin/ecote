// �̰��� �ڵ��׽�Ʈ�� p312 greedy 2��
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
	int ans = 1;
	bool flag = false;

	//����. 1�� ����� ���� ������� ���ߴ�.
	for (int i = 0; i < s.size(); ++i) 
	{
		if (s[i] == '0') continue;
		flag = true;
		ans *= (s[i] - '0');
	}
	if (flag) cout << ans;
	else cout << 0;
	
	//����
	ans = s[0] - '0';
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] - '0' <= 1 || ans <= 1) ans += s[i] - '0';
		else ans *= s[i] - '0';
	}
	cout << ans;
}

