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

//https://leetcode.com/problems/combination-sum-iv/?envType=study-plan&id=dynamic-programming-i
// 377. Combination Sum IV
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long long> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i >= nums[j]) {
					dp[i] += dp[i - nums[j]];
				}
			}
		}
		return dp[target];
	}
};
