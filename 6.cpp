#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define pll pair<long long, long long>
using namespace std;

priority_queue<pll> pq;
int emptyArr[200001];

int solution(vector<int> food_times, long long k) {
    int answer;
    
    long long sum = 0;
    for (int i = 0; i < food_times.size(); ++i) {
        sum += food_times[i];
        pq.push({ -food_times[i], i + 1 });
    }
    if (sum <= k) {
        return -1;
    }
    long long totalTime = 0, prevNum = 0, ftSize = food_times.size();
    while (totalTime + (-pq.top().first - prevNum) * ftSize <= k) {
        totalTime += (-pq.top().first - prevNum) * ftSize;
        prevNum = -pq.top().first;
        pq.pop();
        ftSize--;
    }
    vector<pll> vt;
    while (!pq.empty()) {
        long long inpTime = -pq.top().first, num = pq.top().second;
        vt.push_back({ num, inpTime });
        pq.pop();
    }
    sort(vt.begin(), vt.end());
    answer = vt[(k - totalTime) % ftSize].first;
    return answer;
}
