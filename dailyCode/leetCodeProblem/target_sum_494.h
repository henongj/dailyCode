#ifndef ___target_sum_494_h___
#define ___target_sum_494_h___
//https://leetcode.com/problems/target-sum/
//___target_sum_494_h___
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	void helper(const vector<int>& nums, int target, int sum, int& count, int index)
	{//Runtime: 2794 ms , Memory Usage : 9.1 MB
		if (index == nums.size() && sum == target)
			count += 1;
		else if (index < nums.size())
		{
			helper(nums, target, sum + nums[index], count, index + 1);
			helper(nums, target, sum - nums[index], count, index + 1);
		}
		return;
	}
	void helper2(const vector<int>& nums, int target, int sum, int& count, int index)
	{
		if (index == nums.size() && sum == target)
			count += 1;

		if (index < nums.size())
		{
			helper(nums, target, sum + nums[index], count, index + 1);
			helper(nums, target, sum - nums[index], count, index + 1);
		}
		return;


		/*
		Runtime: 1760 ms, faster than 14.30% of C++ online submissions for Target Sum.
		Memory Usage: 8.9 MB, less than 93.73% of C++ online submissions for Target Sum.
		*/
	}
	int findTargetSumWays(vector<int>& nums, int target) {

		int count = 0;
		helper(nums, target, 0, count, 0);

		return count;
	}
};

#endif