
//https://leetcode.com/problems/house-robber/?envType=study-plan&id=dynamic-programming-i
//198. House Robber
#ifndef ___House_Robber_198_h___
#define ___House_Robber_198_h___
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
	int rob(vector<int>& nums) {
		// 인접한 집은 털 수 없다, 즉 sum += nums[i]를 했다면, sum += nums[i+1]은 할 수 없다
		int len = nums.size();
		// 즉 이전 집은 털 수 없다. 전전 집 + 지금 집 과 전집을 비교해야한다
		if (len == 1)
			return nums[0];

		vector<int> memo(len, 0);
		memo[0] = nums[0];
		memo[1] = max(nums[0], nums[1]);

		for (int idx = 2; idx < len; idx++)
			memo[idx] = max(memo[idx - 1], memo[idx - 2] + nums[idx]);
		return memo[len - 1];
	}
};

#endif // ___House_Robber_198_h___
