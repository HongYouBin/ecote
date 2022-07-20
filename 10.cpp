#include <string>
#include <vector>

#define vvi vector<vector<int>>
using namespace std;

vvi turn(vvi tmp) {
    int nSize = tmp.size();
    vvi newVector(nSize, vector<int>(nSize));
    for (int i = 0; i < nSize; ++i) {
        for (int j = 0; j < nSize; ++j) {
            //tmp[i][j] --> tmp[j][n-i-1]
            newVector[j][nSize - i - 1] = tmp[i][j];
        }
    }
    return newVector;
}

bool check(vvi lock) {
    int n = lock.size() / 3;
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            if (lock[i][j] == 1) continue;
            return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> newLock(n * 3, vector<int>(n * 3));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newLock[i + n][j + n] = lock[i][j];
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            for (int k = 0; k < 4; ++k) {
                key = turn(key);
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < m; ++c) {
                        newLock[i + r][j + c] += key[r][c];
                    }
                }
                if (check(newLock)) return answer;
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < m; ++c) {
                        newLock[i + r][j + c] -= key[r][c];
                    }
                }
            }
        }
    }


    return false;
}

/*
vector<vector<int> > rotateMatrixBy90Degree(vector<vector<int> > a) {
    int n = a.size(); // 행 길이 계산
    int m = a[0].size(); // 열 길이 계산
    vector<vector<int> > result(n, vector<int>(m)); // 결과 리스트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];
        }
    }
    return result;
}
*/