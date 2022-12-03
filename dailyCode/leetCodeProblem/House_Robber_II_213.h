//https://leetcode.com/problems/house-robber-ii/?envType=study-plan&id=dynamic-programming-i
//213. House Robber II
#ifndef ___House_Robber_II_213_h___
#define ___House_Robber_II_213_h___
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
	int rob(vector<int>& nums) {
		// 첫 집을 털면 마지막 집은 털 수 없음
		// 첫 집을 고르면 마지막 집은 못 고름
		int len = nums.size();
		if (len == 1)
			return nums[0];
		if (len == 2)
			return max(nums[0], nums[1]);

		//첫 집 고르는 케이스
		len = nums.size() - 1;
		vector<int> memo1(len, 0);
		memo1[0] = nums[0];
		memo1[1] = nums[0];
		for (int idx = 2; idx < len; idx++)
			memo1[idx] = max(memo1[idx - 1], memo1[idx - 2] + nums[idx]);

		int first_case = memo1[memo1.size() - 1];

		// 두 번째 집을 고르면 마지막 집 고름 
		len = nums.size();
		vector<int> memo2(len, 0);
		memo2[0] = 0;
		memo2[1] = nums[1];
		for (int idx = 2; idx < len; idx++)
			memo2[idx] = max(memo2[idx - 1], memo2[idx - 2] + nums[idx]);

		int second_case = memo2[len - 1];

		return first_case > second_case ? first_case : second_case;
	}
};

#endif // ___House_Robber_II_213_h___
