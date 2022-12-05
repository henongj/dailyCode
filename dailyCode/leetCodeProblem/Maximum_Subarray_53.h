#ifndef ___Maximum_Subarray_53_h___
#define ___Maximum_Subarray_53_h___
//https://leetcode.com/problems/maximum-subarray/?envType=study-plan&id=dynamic-programming-i
//53. Maximum Subarray
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
	int maxSubArray(vector<int>& nums) {
		// 각 dp의 값은 이전까지의 누적 합과 현재 새로운 값중 더 큰 값을 dp에 적는 것이다
		int len = nums.size();
		// dp[i] = max(dp[i-1] + nums[i], nums[i])
		vector<int> dp(len, 0);
		dp[0] = nums[0];
		int maximum = dp[0];
		for (int idx = 1; idx < len; idx++)
		{
			dp[idx] = max(dp[idx - 1] + nums[idx], nums[idx]);
			maximum = max(maximum, dp[idx]);
		}

		return maximum;
	}
};
#endif