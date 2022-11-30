
//https://leetcode.com/problems/contains-duplicate/?envType=study-plan&id=programming-skills-i
//217. Contains Duplicate
#ifndef ___Contains_Duplicate_217_h___
#define ___Contains_Duplicate_217_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
		{
			if (!m.count(nums[i]))
				m[nums[i]] = 1;
			else
				return true;
		}

		return false;
	}
};


#endif // ___Contains_Duplicate_217_h___