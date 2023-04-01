#include<vector>
//https://leetcode.com/problems/binary-search/description/
//704. Binary Search
class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int nNumsLength{};
		int nLeft{};
		int nRight{};
		int nMiddle{};

		nNumsLength = nums.size();
		nLeft = 0;
		nRight = nNumsLength - 1;

		while (nLeft <= nRight)
		{
			nMiddle = (nLeft + nRight) / 2;

			if (nums[nMiddle] == target)
				return nMiddle;
			else if (nums[nMiddle] < target)
				nLeft = nMiddle + 1;
			else
				nRight = nMiddle - 1;
		}

		return -1;
	}
};