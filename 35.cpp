#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int n, maxNum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<int> vt;
	map<int, int> mp;
	priority_queue<int, vector<int>, greater<>> pq;
	pq.push(1);

	cin >> n;
	while(vt.size()!=n){
		int num = pq.top(); pq.pop();
		if (mp[num])continue;
		vt.push_back(num);
		mp[num] = num;
		pq.push(num * 2);
		pq.push(num * 3);
		pq.push(num * 5);
	}
	cout << vt[n - 1];
}
