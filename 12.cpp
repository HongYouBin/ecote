#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(vector<vector<int>> build) {
    for (int i = 0; i < build.size(); ++i)
    {
        int x = build[i][0], y = build[i][1], object = build[i][2];
        if (object)
        {
            bool flag = false;
            bool right = false;
            bool left = false;
            for (int j = 0; j < build.size(); ++j)
            {
                if (x == build[j][0] && y - 1 == build[j][1] && build[j][2] == 0)flag = true;
                if (x + 1 == build[j][0] && y - 1 == build[j][1] && build[j][2] == 0)flag = true;
                if (x - 1 == build[j][0] && y == build[j][1] && build[j][2] == 1) right = true;
                if (x + 1 == build[j][0] && y == build[j][1] && build[j][2] == 1) left = true;
            }
            if (right && left) flag = true;
            if (!flag) return false;
        }
        else
        {
            bool flag = false;
            if (y == 0) flag = true;
            for (int j = 0; j < build.size(); ++j)
            {
                if (x - 1 == build[j][0] && y == build[j][1] && 1 == build[j][2]) flag = true;
                if (x == build[j][0] && y == build[j][1] && 1 == build[j][2]) flag = true;
                if (x == build[j][0] && y - 1 == build[j][1] && build[j][2] == 0) flag = true;
            }
            if (!flag) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); ++i)
    {
        int x = build_frame[i][0], y = build_frame[i][1], object = build_frame[i][2], construct = build_frame[i][3];
        if (construct)
        {
            vector<int> tmp;
            tmp.push_back(x);
            tmp.push_back(y);
            tmp.push_back(object);
            answer.push_back(tmp);
            if (!check(answer)) answer.pop_back();
        }
        else
        {
            int index;
            for (int j = 0; j < answer.size(); ++j)
            {
                if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == object)
                {
                    index = j;
                }
                vector<int> erased = answer[index];
                answer.erase(answer.begin() + index);
                if (!check(answer)) answer.push_back(erased);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

