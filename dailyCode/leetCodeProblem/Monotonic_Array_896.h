
//https://leetcode.com/problems/monotonic-array/?envType=study-plan&id=programming-skills-ii
//896. Monotonic Array
#ifndef ___Monotonic_Array_896_h___
#define ___Monotonic_Array_896_h___

#include<vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
		int n = nums.size();
		int flag = 0;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			int t = nums[i] - nums[i + 1];
			if (t == 0)
				continue;

			if (flag == 0)
			{
				if (t > 0)
					flag = 1;
				if (t < 0)
					flag = -1;
			}
			
			if (flag > 0)
			{
				if (t < 0)
					return false;
			}

			if (flag < 0)
			{
				if (t > 0)
					return false;
			}
		}

		return true;
    }
};

#endif// ___Monotonic_Array_896_h___