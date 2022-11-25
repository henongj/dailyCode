//https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=programming-skills-i
//283. Move Zeroes
#ifndef ___Move_Zeroes_283_h___
#define ___Move_Zeroes_283_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zero_count = 0;
		vector<int> result;
		for (auto num : nums)
		{
			if (num == 0)
				zero_count++;
			if (num != 0)
				result.push_back(num);
		}
		for (; zero_count > 0; zero_count--)
			result.push_back(0);

		nums = result;
	}
};


#endif // ___Move_Zeroes_283_h___