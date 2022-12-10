
//https://leetcode.com/problems/arithmetic-slices/?envType=study-plan&id=dynamic-programming-i
//413. Arithmetic Slices
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

#ifndef ___Arithmetic_Slices_413_h___
#define ___Arithmetic_Slices_413_h___
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
		int result = 0;
		int len = nums.size();
		
		if (len < 3) 
			return 0;
		
		vector<int> dp(len,0);
		for (int i = 0; i < len; i++)
			dp[i] = 0;
		
		// ���� ���̰� 1�� �� ������ len-1...3���� ���������� �ϳ��� �� ���ܳ���
		// �� ���̰� 5���� 6���� �þ�� ���� ���� 5,4,3�� ���� 6, 4���� �þ��
		
		for (int i = 2; i < len; i++)
		{
			if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
			{
				dp[i] = dp[i - 1] + 1;
				result += dp[i];
			}
		}
		
		
		return result;
    }
};

#endif// ___Arithmetic_Slices_413_h___

