#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define inf 1e9
using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void move(int(*numArr)[4], int(*dirArr)[4]) {
	for (int num = 1; num <= 16; ++num) {
		int row = -1, col = -1, dir = -1;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (numArr[i][j] == num) {
					row = i;
					col = j;
					dir = dirArr[i][j];
					break;
				}
			}
		}
		if (dir == -1) continue;
		for (int i = 0; i < 8; ++i) {
			int nRow = row + dx[dir - 1], nCol = col + dy[dir - 1];
			if (nRow < 0 || 4 <= nRow || nCol < 0 || 4 <= nCol || numArr[nRow][nCol] == inf) {
				dir++;
				if (dir == 9) dir = 1;
				continue;
			}
			dirArr[row][col] = dir;
			swap(numArr[nRow][nCol], numArr[row][col]);
			swap(dirArr[nRow][nCol], dirArr[row][col]);
			break;
		}
	}
}

int solv(int(*numMemo)[4], int(*dirMemo)[4], int row, int col, int level) {
	int sum = numMemo[row][col];
	int dir = dirMemo[row][col];
	int maxSum = 0;

	int numArr[4][4], dirArr[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			numArr[i][j] = numMemo[i][j];
			dirArr[i][j] = dirMemo[i][j];
		}
	}
	numArr[row][col] = inf;
	// fish moving
	move(numArr, dirArr);
	numArr[row][col] = 0;
	int nRow = row, nCol = col;
	for (int i = 0; i < 4; ++i) {
		nRow = nRow + dx[dir - 1], nCol = nCol + dy[dir - 1];
		if (0 <= nRow && nRow < 4 && 0 <= nCol && nCol < 4 && numArr[nRow][nCol] != 0) {
			maxSum = max(maxSum, solv(numArr, dirArr, nRow, nCol, level + 1));
		}
	}
	return sum + maxSum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int num, dir;
	int numArr[4][4], dirArr[4][4];

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> numArr[i][j] >> dirArr[i][j];
		}
	}
	cout << solv(numArr, dirArr, 0, 0, 0) << '\n';
}