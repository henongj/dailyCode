//https://leetcode.com/problems/sign-of-the-product-of-an-array/
//1822. Sign of the Product of an Array
#ifndef ___Sign_of_the_Product_of_an_Array_1822_h___
#define ___Sign_of_the_Product_of_an_Array_1822_h___
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
	int arraySign(vector<int>& nums) {
		int result = 1;
		for (auto num : nums)
		{
			if (num > 0)
				result *= 1;
			if (num < 0)
				result *= -1;
			if (num == 0)
				result *= 0;
		}

		return result;
	}
};
/*
testcase
[-1,-2,-3,-4,3,2,1]
[1,5,0,2,-3]
[-1,1,-1,1,-1]

*/
#endif