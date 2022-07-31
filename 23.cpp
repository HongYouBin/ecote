#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int kor;
	int eng;
	int math;

	Student(string name, int kor, int eng, int math) {
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}
};

int n;
vector<Student> vt;

bool cmp(Student a, Student b) {
	if (a.kor != b.kor) return a.kor > b.kor;
	else if (a.eng != b.eng) return a.eng < b.eng;
	else if (a.math != b.math) return a.math > b.math;
	else return a.name < b.name;
}

int main() {
	cin >> n;
	string name;
	int kor, eng, math;
	for (int i = 0; i < n; ++i) {
		cin >> name >> kor >> eng >> math;
		vt.push_back(Student(name, kor, eng, math));
	}
	sort(vt.begin(), vt.end(), cmp);
	for (int i = 0; i < n; ++i) cout << vt[i].name << '\n';
}
