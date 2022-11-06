/*
Largest Perimeter Triangle 976
https://leetcode.com/problems/largest-perimeter-triangle/?envType=study-plan&id=programming-skills-i


*/

#ifndef ___Largest_Perimeter_Triangle_976_h___
#define ___Largest_Perimeter_Triangle_976_h___

class Solution {
public:
	bool canMakeTriangle(const int& a, const int& b, const int& c) {
		return a + b > c && a + c > b && b + c > a;
	}
	int largestPerimeter(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		for (int i = nums.size() - 1; i >= 2; i--)
		{
			if (canMakeTriangle(nums[i], nums[i - 1], nums[i - 2]))
			{
				return nums[i] + nums[i - 1] + nums[i - 2];
			}
		}
		return 0;

	}
};

#endif
