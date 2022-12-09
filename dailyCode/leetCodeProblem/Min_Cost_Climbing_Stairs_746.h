
//https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
//746. Min Cost Climbing Stairs
#ifndef ___Min_Cost_Climbing_Stairs_746_h___
#define ___Min_Cost_Climbing_Stairs_746_h___
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
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[n];
	}
};
class Solution2 {
public:
	void find_minimum_cost(vector<int>& cost, vector<int>& memo, int idx)
	{
		if (idx >= memo.size())
			return;
		
		find_minimum_cost(cost, memo, idx + 1);
		memo[idx] = cost[idx] + min(memo[idx - 1], memo[idx - 2]);
	}
	int minCostClimbingStairs(vector<int>& cost) {

		cost.push_back(0);
		vector<int> memo(cost.size(), 10000000);
		memo[0] = cost[0];
		memo[1] = cost[1];
		
		find_minimum_cost(cost, memo, 2);
		return memo[memo.size()-1];
	}
};

#endif //___Min_Cost_Climbing_Stairs_746_h___