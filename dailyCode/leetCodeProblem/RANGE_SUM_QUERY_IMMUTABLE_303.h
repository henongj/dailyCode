
//https://leetcode.com/problems/range-sum-query-immutable/?envType=study-plan&id=programming-skills-i
//303. Range Sum Query - Immutable
#ifndef ___RANGE_SUM_QUERY_IMMUTABLE_303_H___
#define ___RANGE_SUM_QUERY_IMMUTABLE_303_H___
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

class NumArray {
public:
	vector<int> nums;
	NumArray(vector<int>& nums) {
		this->nums = nums;
	}

	int sumRange(int left, int right) {
		int sum = 0;
		for (int idx = left; idx <= right; idx++)
			sum += nums[idx];
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */


#endif // ___RANGE_SUM_QUERY_IMMUTABLE_303_H___
