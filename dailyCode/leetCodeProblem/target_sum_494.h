//https://leetcode.com/problems/target-sum/
//___target_sum_494_h___
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	void helper(const vector<int>& nums, int target, int sum, int& count, int index)
	{
		if (index == nums.size() && sum == target)
			count += 1;
		else if (index < nums.size())
		{
			helper(nums, target, sum + nums[index], count, index + 1);
			helper(nums, target, sum - nums[index], count, index + 1);
		}
		return;
	}
	int findTargetSumWays(vector<int>& nums, int target) {

		int count = 0;
		helper(nums, target, 0, count, 0);

		return count;
	}
};