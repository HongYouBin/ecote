#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int ans = 50000;


	for (int i = 1; i <= s.length() / 2 + 1; i++)
	{
		string nxt, compressed, prev;
		prev = s.substr(0, i);
		int count = 1;
		for (int j = i; j < s.length(); j += i)
		{
			nxt = s.substr(j, i);
			if (nxt == prev) count++;
			else
			{
				compressed += count > 1 ? to_string(count) + prev : prev;
				prev = nxt;
				count = 1;
			}
		}
		compressed += count > 1 ? to_string(count) + prev : prev;
		ans = min(ans, (int)compressed.length());
	}
	return ans;
}