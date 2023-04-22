#pragma once
#include<string>
#include<vector>
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
class Solution {
public:
	int minInsertions(std::string s) {

		std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1];
				}
				else {
					dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
				}

			}
		}
		return dp[0][s.size() - 1];
	}
};