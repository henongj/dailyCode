//https://leetcode.com/problems/maximum-product-subarray/?envType=study-plan&id=dynamic-programming-i
//152. Maximum Product Subarray
#ifndef ___Maximum_Product_Subarray_152_h___
#define ___Maximum_Product_Subarray_152_h___
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

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return 0;

		int maxProduct = nums[0];
		int minProduct = nums[0];
		int result = nums[0];
		for (int i = 1; i < len; i++) {
			int temp = maxProduct;
			maxProduct = max(max(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
			minProduct = min(min(temp * nums[i], minProduct * nums[i]), nums[i]);
			result = max(maxProduct, result);
		}
		return result;

	}
};

#endif // ___Maximum_Product_Subarray_152_h___