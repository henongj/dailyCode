#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

//  167 797
// https://leetcode.com/problems/palindrome-partitioning/
// 131. Palindrome Partitioning
// ___Palindrome_Partitioning_131_h___

/*
* ---- recursion ---
1. (팰린드롬인지 검사) push_back
2. (string 길이에 맞춰서 반복 호출)
3. ( 검사할 string 길이를 늘려서 recursion)

*/
class Solution {
public:
	inline bool is_palindrome(const string& s)
	{
		if (s.size() == 1)
			return true;
		
		int start = 0;
		int end = s.size() - 1;
		while(start < end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
	void get_palindrome_string_same_length(vector<string>& v , const string& s, int length)
	{
		for (int i = 0; i < s.size() - length + 1; i++)
		{
			if (is_palindrome(s.substr(i, length)))
				v.push_back(s.substr(i, length));
		}
	}
	
    vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		if (s.size() == 0)
			return result;
		
		vector<string> palindromes;
		for (int len = 1; len < s.size(); len++)
		{
			get_palindrome_string_same_length(palindromes, s, len);
			result.push_back(palindromes);
			palindromes.clear();
		}
		return result;
    }
};



int main(void)
{
	
	return 0;
}
