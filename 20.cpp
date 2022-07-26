#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int,int>
using namespace std;

int n;
char arr[40][40];
vector<pii> emptySpace, teacher;

bool upCheck(int row, int col) {
	if (row < 0 || n <= row || col < 0 || n <= col) return true;
	if (arr[row][col] == 'S') return false;
	else if (arr[row][col] == 'O') return true;
	return upCheck(row - 1, col);
}

bool downCheck(int row, int col) {
	if (row < 0 || n <= row || col < 0 || n <= col) return true;
	if (arr[row][col] == 'S') return false;
	else if (arr[row][col] == 'O') return true;
	return downCheck(row + 1, col);
}

bool rightCheck(int row, int col) {
	if (row < 0 || n <= row || col < 0 || n <= col) return true;
	if (arr[row][col] == 'S') return false;
	else if (arr[row][col] == 'O') return true;
	return rightCheck(row, col + 1);
}

bool leftCheck(int row, int col) {
	if (row < 0 || n <= row || col < 0 || n <= col) return true;
	if (arr[row][col] == 'S') return false;
	else if (arr[row][col] == 'O') return true;
	return leftCheck(row, col - 1);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X')emptySpace.push_back({ i,j });
			else if (arr[i][j] == 'T') teacher.push_back({ i,j });
		}
	}
	vector<int> bin(emptySpace.size());
	fill(bin.end() - 3, bin.end(), 1);
	vector<bool> flag(teacher.size());
	do {
		bool ans = true;
		vector<pii> memo;
		fill(flag.begin(), flag.end(), false);
		//for (int i = 0; i < 3; ++i)flag[i] = false;
		for (int i = 0; i < bin.size(); ++i) {
			if (!bin[i]) continue;
			memo.push_back({ emptySpace[i].first, emptySpace[i].second });
			arr[emptySpace[i].first][emptySpace[i].second] = 'O';
		}

		for (int i = 0; i < teacher.size(); ++i) {
			int row = teacher[i].first;
			int col = teacher[i].second;
			if (upCheck(row, col) && downCheck(row, col) && rightCheck(row, col) && leftCheck(row, col)) flag[i] = true;
		}
		for (int i = 0; i < 3; ++i) {
			arr[memo[i].first][memo[i].second] = 'X';
		}
		for (int i = 0; i < flag.size(); ++i) {
			if (flag[i] == false) ans = false;
		}
		if (ans) {
			cout << "YES" << '\n';
			return 0;
		}
	} while (next_permutation(bin.begin(), bin.end()));
	cout << "NO" << '\n';
}