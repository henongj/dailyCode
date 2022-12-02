
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

#endif //___Min_Cost_Climbing_Stairs_746_h___