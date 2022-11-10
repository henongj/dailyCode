#ifndef ___Palindrome_Partitioning_131_h___
#define ___Palindrome_Partitioning_131_h___
/* https ://leetcode.com/problems/palindrome-partitioning/
131. Palindrome Partitioning
1. (string�� ���� ū ũ��� �߶󰡸� palindrome ������)
2. (�������� ������ ����� ���� ���� �߶� �־�� �Ѵ�)
  ex) aaaaaabbbbbbaabbc �϶� len = 5���
		a5 b5 {a,a,b,b,c} {aa,b,b,c} {aa,bb,c} {a,a,bb,c} 4����
3. �̷� ���, ������� ����� ���� ��� �ڵ� ������ pop�� �ʿ䰡 �ִ�
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