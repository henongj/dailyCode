#ifndef ___Palindrome_Partitioning_131_h___
#define ___Palindrome_Partitioning_131_h___
/* https ://leetcode.com/problems/palindrome-partitioning/
131. Palindrome Partitioning
1. (string을 점점 큰 크기로 잘라가며 palindrome 돌리기)
2. (자투리가 남으면 경우의 수에 따라 잘라 넣어야 한다)
  ex) aaaaaabbbbbbaabbc 일때 len = 5라면
		a5 b5 {a,a,b,b,c} {aa,b,b,c} {aa,bb,c} {a,a,bb,c} 4가지
3. 이럴 경우, 집어넣은 경우의 수를 재귀 코드 내에서 pop할 필요가 있다
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	inline bool is_palindrome(const string& s)
	{
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
	void dfs(vector<vector<string>>& result, vector<string>& divided, const string& s, int start)
	{
		if (start == s.size())
		{
			result.push_back(divided);
			return;
		}
		for (int i = start; i < s.size(); i++)
		{
			string sub = s.substr(start, i - start + 1);
			if (is_palindrome(sub))
			{
				divided.push_back(sub);
				dfs(result, divided, s, i + 1);
				divided.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> divided;
		dfs(result, divided, s, 0);
		return result;
	}
};
#endif