
//https://leetcode.com/problems/delete-and-earn/?envType=study-plan&id=dynamic-programming-i
//740. Delete and Earn
#ifndef ___Delete_and_Earn_740_h___
#define ___Delete_and_Earn_740_h___
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
	int deleteAndEarn(vector<int>& nums) {
		int maxNum = 0;
		// 최대인 숫자를 찾는다.
		for (int i = 0; i < nums.size(); i++)
			maxNum = max(maxNum, nums[i]);

		// 각 숫자의 개수를 센다.
		vector<int> sum(maxNum + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			sum[nums[i]] += nums[i];

		// 2개씩 묶어서 더한다.
		vector<int> dp(maxNum + 1, 0);
		dp[1] = sum[1];
		for (int i = 2; i <= maxNum; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);

		return dp[maxNum];
	}
};


#endif // ___Delete_and_Earn_740_h___