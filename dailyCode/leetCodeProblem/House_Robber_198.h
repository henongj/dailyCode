
//https://leetcode.com/problems/house-robber/?envType=study-plan&id=dynamic-programming-i
//198. House Robber
#ifndef ___House_Robber_198_h___
#define ___House_Robber_198_h___
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
		// ������ ���� �� �� ����, �� sum += nums[i]�� �ߴٸ�, sum += nums[i+1]�� �� �� ����
		int len = nums.size();
		// �� ���� ���� �� �� ����. ���� �� + ���� �� �� ������ ���ؾ��Ѵ�
		if (len == 1)
			return nums[0];

		vector<int> memo(len, 0);
		memo[0] = nums[0];
		memo[1] = max(nums[0], nums[1]);

		for (int idx = 2; idx < len; idx++)
			memo[idx] = max(memo[idx - 1], memo[idx - 2] + nums[idx]);
		return memo[len - 1];
	}
};

#endif // ___House_Robber_198_h___
