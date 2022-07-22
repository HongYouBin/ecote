#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int weakArr[210];

int solution(int n, vector<int> weak, vector<int> dist) {
    int ans = dist.size() + 10;

    int length = weak.size();
    for (int i = 0; i < length; ++i)weak.push_back(weak[i] + n);
    
    for (int start = 0; start < length; ++start) {
        do {
            int cnt = 1;
            int location = weak[start] + dist[cnt - 1];
            for (int i = start; i < start + length; ++i) {
                if (location < weak[i]) {
                    cnt++;
                    if (cnt > dist.size())break;
                    location = weak[i] + dist[cnt - 1];
                }
            }
            ans = min(ans, cnt);
        } while (next_permutation(dist.begin(), dist.end()));
    }
    if (ans > dist.size()) return -1;
    return ans;
}

int main() {
    int n = 12;
    vector<int> f;
    f.push_back(1);
    f.push_back(5);
    f.push_back(6);
    f.push_back(10);
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    cout << solution(n, f, s);
}