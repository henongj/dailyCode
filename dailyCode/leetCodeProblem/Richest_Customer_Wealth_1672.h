
//https://leetcode.com/problems/richest-customer-wealth/?envType=study-plan&id=programming-skills-i
//1672. Richest Customer Wealth
#ifndef ___Richest_Customer_Wealth_1672_h___
#define ___Richest_Customer_Wealth_1672_h___
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
	int maximumWealth(vector<vector<int>>& accounts) {
		auto get_vector_sum = [](const vector<vector<int>>& accounts, int index) -> int {
			int sum = 0;
			for (int idx = 0; idx < accounts[index].size(); idx++)
				sum += accounts[index][idx];
			return sum;
		};
		int result = 0;
		for (int i = 0; i < accounts.size(); i++)
			result = max(result, get_vector_sum(accounts, i));
		return result;
	}
};

#endif // !___Richest_Customer_Wealth_1672_h___
