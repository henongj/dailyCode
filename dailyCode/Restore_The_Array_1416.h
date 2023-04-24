#pragma once
#include<vector>
#include<string>
//https://leetcode.com/problems/restore-the-array/
//1416. Restore The Array
class Solution {
public:
	int numberOfArrays(std::string s, int k) {
		int n = s.size();
		std::vector<int> dp(n + 1, 0);
		dp[n] = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == '0') continue;
			long long num = 0;
			for (int j = i; j < n; ++j) {
				num = num * 10 + s[j] - '0';
				if (num > k) break;
				dp[i] = (dp[i] + dp[j + 1]) % 1000000007;
			}
		}
		return dp[0];
	}
};