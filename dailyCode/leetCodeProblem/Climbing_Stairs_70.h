

//https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=dynamic-programming-i
//70. Climbing Stairs
#ifndef ___Climbing_Stairs_70_h___
#define ___Climbing_Stairs_70_h___
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
	int climbStairs(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};

class Solution2 {
public:
	int get_step_count(vector<int>& memo, int n)
	{
		if (memo[n] != 0)
			return memo[n];
		memo[n] = get_step_count(memo, n - 1) + get_step_count(memo, n - 2);
		return memo[n];
	}
	int climbStairs(int n) {
		vector<int> memo(n + 2, 0);

		memo[0] = 0; memo[1] = 1; memo[2] = 2;

		if (n < 3)
			return memo[n];

		return get_step_count(memo, n);
	}
};

#endif // ___Climbing_Stairs_70_h___
