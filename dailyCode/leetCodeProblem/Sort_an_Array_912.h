#pragma once
#include<iostream>

#include<algorithm>
#include<vector>
//https://leetcode.com/problems/sort-an-array/description/
//912. Sort an Array
class Solution {
public:
	std::vector<int> sortArray(std::vector<int>&nums) {
		std::sort(nums.begin(), nums.end());
		return nums;
	}
};