#include <string>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int r1, c1, r2, c2;
    Node(int r1, int c1, int r2, int c2) {
        this->r1 = r1;
        this->r2 = r2;
        this->c1 = c1;
        this->c2 = c2;
    }
};

vector<Node> visited;
queue<pair<int, Node>> q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<Node> check(vector<vector<int>> board, Node curNode) {
    vector<Node> nxtPos;
    for (int i = 0; i < 4; ++i) {
        if (board[curNode.r1 + dx[i]][curNode.c1 + dy[i]] || board[curNode.r2 + dx[i]][curNode.c2 + dy[i]]) continue;
        nxtPos.push_back(Node(curNode.r1 + dx[i], curNode.c1 + dy[i], curNode.r2 + dx[i], curNode.c2 + dy[i]));
    }

    int pos[2] = { -1, 1 };
    if (curNode.r1 == curNode.r2) {
        for (int i = 0; i < 2; ++i) {
            if (board[curNode.r1 + pos[i]][curNode.c1] || board[curNode.r2 + pos[i]][curNode.c2])continue;
            nxtPos.push_back(Node(curNode.r1, curNode.c1, curNode.r2 + pos[i], curNode.c1));
            nxtPos.push_back(Node(curNode.r2, curNode.c2, curNode.r1 + pos[i], curNode.c2));

        }
    }
    else {
        for (int i = 0; i < 2; ++i) {
            if (board[curNode.r1][curNode.c1 + pos[i]] || board[curNode.r2][curNode.c2 + pos[i]])continue;
            nxtPos.push_back(Node(curNode.r1, curNode.c1+pos[i], curNode.r1, curNode.c1));
            nxtPos.push_back(Node(curNode.r2, curNode.c2 + pos[i], curNode.r2, curNode.c2));
        }
    }
    return nxtPos;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> newBoard(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }

    Node curNode(1, 1, 1, 2);
    q.push({ 0, curNode });
    visited.push_back(curNode);
    
    while (!q.empty()) {
        int time = q.front().first;
        curNode = q.front().second; q.pop();
        if (curNode.r1 == n && curNode.c1 == n || curNode.r2 == n && curNode.c2 == n) {
            return time;
        }
        vector<Node> nxtNode = check(newBoard, curNode);
        for (auto checkNode : nxtNode) {
            bool flag = true;
            for (int j = 0; j < visited.size(); ++j) {
                if (checkNode.r1 == visited[j].r1 && checkNode.c1 == visited[j].c1 && checkNode.r2 == visited[j].r2 &&checkNode.c2 == visited[j].c2) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                visited.push_back(checkNode);
                q.push({ time + 1, checkNode });
            }
        }
    }

    //int answer = 0;
    //return answer;
}