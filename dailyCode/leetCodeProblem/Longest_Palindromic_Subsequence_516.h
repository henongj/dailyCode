//https://leetcode.com/problems/longest-palindromic-subsequence/description/?envType=study-plan&id=dynamic-programming-i
//516. Longest Palindromic Subsequence
#ifndef ___Longest_Palindromic_Subsequence_516_h___
#define ___Longest_Palindromic_Subsequence_516_h___
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
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};

#endif // ___Longest_Palindromic_Subsequence_516_h___
