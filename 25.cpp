#include <vector>
#include <algorithm>

using namespace std;

int arr[505];
vector<pair<double, int>> vt;

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
    //if (a.first == b.first) return a.second < b.second;
    //else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    for (int i = 1; i <= N; ++i) {
        int cnt = count(stages.begin(), stages.end(), i);
        double fail = 0;
        if (num) {
            fail = double(cnt) / num;
        }
        vt.push_back({ fail, i });
        num -= cnt;
    }
    sort(vt.begin(), vt.end(), cmp);
    for (int i = 0; i < vt.size(); ++i) {
        answer.push_back(vt[i].second);
    }
    return answer;
}
