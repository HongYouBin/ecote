#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int n, arr[50], oper[4], minAns = 1e9, maxAns = -1e9;
vector<int> vt;

void solv(int order, int number, int plu, int minu, int mul, int div) {
	if (order == n) {
		minAns = min(minAns, number);
		maxAns = max(maxAns, number);
		return;
	}
	if (minu) solv(order + 1, number - arr[order], plu, minu - 1, mul, div);
	if (plu) solv(order + 1, number + arr[order], plu - 1, minu, mul, div);
	if (mul) solv(order + 1, number * arr[order], plu, minu, mul - 1, div);
	if (div) solv(order + 1, number / arr[order], plu, minu, mul, div - 1);
	return;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	for (int i = 0; i < 4; ++i)cin >> oper[i];
	solv(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	cout << maxAns << '\n' << minAns << '\n';
}