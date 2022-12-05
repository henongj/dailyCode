
#ifndef ___Maximum_Sum_Circular_Subarray_918_h___
#define ___Maximum_Sum_Circular_Subarray_918_h___
//https://leetcode.com/problems/maximum-sum-circular-subarray/
//918. Maximum Sum Circular Subarray
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
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int maxSum = nums[0];
		int minSum = nums[0];
		int sum = nums[0];
		int maxSumAll = nums[0];
		int minSumAll = nums[0];
		for (int i = 1; i < n; i++) {
			maxSum = max(maxSum + nums[i], nums[i]);
			minSum = min(minSum + nums[i], nums[i]);
			sum += nums[i];
			maxSumAll = max(maxSumAll, maxSum);
			minSumAll = min(minSumAll, minSum);
		}
		if (sum == minSumAll) return maxSumAll;
		return max(maxSumAll, sum - minSumAll);

	}
};
#endif // !___Maximum_Sum_Circular_Subarray_918_h___