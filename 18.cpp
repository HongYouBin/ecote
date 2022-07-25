#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solv(string p) {
    if (p.empty()) return p;

    int openCount = 0, closeCount = 0;
    string u, v, newU;
    stack<char> st;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') {
            openCount++;
            st.push('(');
        }
        else {
            closeCount++;
            if (!st.empty()) st.pop();
        }
        u += p[i];
        if (openCount == closeCount) break;
    }
    for (int i = u.size(); i < p.size(); ++i) v += p[i];
    
    if (!st.empty()) {
        newU = '(';
        newU += solv(v);
        for (int i = 1; i < u.size() - 1; ++i) {
            if (u[i] == '(') newU += ')';
            else newU += '(';
        }
        newU += ')';
        return newU;
    }
    return u + solv(v);
}

string solution(string p) {
    string answer = "";
    answer = solv(p);
    return answer;
}

int main() {
    string s = "()))((()";
    cout << solution(s);
}