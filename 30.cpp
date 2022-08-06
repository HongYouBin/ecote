#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<string> vt[10005];
vector<string> reverseVt[10005];

string firstStr(string s) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '?') continue;
		s[i] = 'a';
	}
	return s;
}

string secondStr(string s) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '?') continue;
		s[i] = 'z';
	}
	return s;
}

string replaceStr(string str, string from, string to) {
	string res = str;
	int pos = 0;
	while ((pos = res.find(from, pos)) != string::npos) {
		res.replace(pos, from.size(), to);
		pos += to.size();
	}
	return res;
}

int countWord(vector<string>& word, string firstS, string secondS) {
	int leftIdx = lower_bound(word.begin(), word.end(), firstS) - word.begin();
	int rightIdx = lower_bound(word.begin(), word.end(), secondS) - word.begin();
	return rightIdx - leftIdx;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	//return answer;
	for (int i = 0; i < words.size(); ++i) {
		string newWord = words[i];
		int len = newWord.length();
		vt[len].push_back(newWord);
		reverse(newWord.begin(), newWord.end());
		reverseVt[len].push_back(newWord);
	}
	for (int i = 0; i < 10001; ++i) {
		sort(vt[i].begin(), vt[i].end());
		sort(reverseVt[i].begin(), reverseVt[i].end());
	}

	for (int i = 0; i < queries.size(); ++i) {
		string q = queries[i];
		int len = q.length();
		int res = 0;
		
		if (queries[i][0] != '?') answer.push_back(countWord(vt[len], firstStr(queries[i]), secondStr(queries[i])));
		else {
			reverse(queries[i].begin(), queries[i].end());
			answer.push_back(countWord(reverseVt[len], firstStr(queries[i]), secondStr(queries[i])));
		}
		/*
		if (q[0] != '?') res = (countWord(vt[len], replaceStr(q, "?", "a"), replaceStr(q, "?", "z")));
		else {
			reverse(q.begin(), q.end());
			res = (countWord(reverseVt[len], replaceStr(q, "?", "a"), replaceStr(q, "?", "z")));
		}
		answer.push_back(res);
		*/
	}
	return answer;
}
