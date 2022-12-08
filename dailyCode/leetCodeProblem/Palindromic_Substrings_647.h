//https://leetcode.com/problems/palindromic-substrings/
//647. Palindromic Substrings
#ifndef ___Palindromic_Substrings_647_h___
#define ___Palindromic_Substrings_647_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;
class Solution {
public:
	int countPalindromic(string& s, int left, int right)
	{
		int count = 0;
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			count++;
			left--;
			right++;
		}
		return count;
	}
	int countSubstrings(string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			count += countPalindromic(s, i, i);
			count += countPalindromic(s, i, i + 1);
		}
		return count;
	}
};
#endif //___Palindromic_Substrings_647_h___