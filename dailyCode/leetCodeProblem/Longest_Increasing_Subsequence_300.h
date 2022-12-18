
//https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan&id=dynamic-programming-i
//300. Longest Increasing Subsequence
#ifndef ___Longest_Increasing_Subsequence_300_h___
#define ___Longest_Increasing_Subsequence_300_h___
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
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> dp(nums.size(), 1);
		int maxLen = 1;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
			}
			maxLen = max(maxLen, dp[i]);
		}
		return maxLen;
	}
};
#endif // ___Longest_Increasing_Subsequence_300_h___
