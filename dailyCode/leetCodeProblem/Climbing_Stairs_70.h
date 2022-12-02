

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

#endif // ___Climbing_Stairs_70_h___
