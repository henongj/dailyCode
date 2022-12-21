
//https://leetcode.com/problems/integer-break/?envType=study-plan&id=dynamic-programming-i
//343. Integer Break
#ifndef ___Integer_Break_343_h___
#define ___Integer_Break_343_h___
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
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}
};
#endif // ___Integer_Break_343_h___