#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, k, m, l, arr[105][105];
queue<pair<int, char>> que;
queue<pair<int, int>> lastPos;
string s;
int direction;

void turn(char state) {
	if (state == 'L') direction = direction == 3 ? 0 : direction + 1;
	else direction = (direction + 1) % 4;
}


int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	direction = 0;
	cin >> n >> k;
	int row, col;
	for (int i = 0; i < k; ++i) {
		cin >> row >> col;
		arr[row][col] = 1;
	}
	cin >> l;
	int second;
	char dir;
	for (int i = 0; i < l; ++i) {
		cin >> second >> dir;
		que.push({ second, dir });
	}
	arr[row][col] = 2;
	lastPos.push({ 1, 1 });
	int time = 0;
	int x = 1, y = 1;

	while (true) 
	{
		int nextX = x+ dx[direction];
		int nextY = y + dy[direction];

		if (nextX < 1 || n < nextX || nextY < 1 || n < nextY || arr[nextX][nextY] == 2) break;
		if (arr[nextX][nextY] == 0)
		{
			auto deletePos = lastPos.front(); lastPos.pop();
			arr[deletePos.first][deletePos.second] = 0;
			arr[nextX][nextY] = 2;
			lastPos.push({ nextX, nextY });
		}
		else
		{
			lastPos.push({ nextX, nextY });
			arr[nextX][nextY] = 2;
		}
		x = nextX;
		y = nextY;
		time++;
		if (time == que.front().first)
		{
			turn(que.front().second);
			que.pop();
		}
	}
	cout << time + 1;
}