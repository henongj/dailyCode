
//https://leetcode.com/problems/longest-palindromic-substring/?envType=study-plan&id=dynamic-programming-i
//5. Longest Palindromic Substring
#ifndef ___Longest_Palindromic_Substring_5_h___
#define ___Longest_Palindromic_Substring_5_h___
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
	int expandAroundCenter(string s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.size() && s[L] == s[R]) {
			L--;
			R++;
		}
		return R - L - 1;
	}

	string longestPalindrome(string s) {
		int n = s.size();

		if (n == 0)
			return "";
		int start = 0;
		int end = 0;
		for (int i = 0; i < n; i++) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};
#endif // ___Longest_Palindromic_Substring_5_h___