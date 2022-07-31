#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		pq.push(num);
	}
	while (pq.size()!=1) {
		int sum = 0;
		sum += pq.top(); pq.pop();
		sum += pq.top(); pq.pop();
		pq.push(sum);
		ans += sum;
	}
	cout << ans << '\n';
}