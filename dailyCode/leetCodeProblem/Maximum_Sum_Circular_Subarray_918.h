
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
		int maxSumSoFar = nums[0];
		int minSumSoFar = nums[0];
		for (int i = 1; i < n; i++) {
			sum += nums[i];
			maxSumSoFar = max(maxSumSoFar + nums[i], nums[i]);
			maxSum = max(maxSum, maxSumSoFar);
			minSumSoFar = min(minSumSoFar + nums[i], nums[i]);
			minSum = min(minSum, minSumSoFar);
		}
		if (maxSum < 0) return maxSum;
		return max(maxSum, sum - minSum);
	}
};
#endif // !___Maximum_Sum_Circular_Subarray_918_h___