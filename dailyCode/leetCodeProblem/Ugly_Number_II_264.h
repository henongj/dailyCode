
//https://leetcode.com/problems/ugly-number-ii/?envType=study-plan&id=dynamic-programming-i
//264. Ugly Number II
#ifndef ___Ugly_Number_II_264_h___
#define ___Ugly_Number_II_264_h___
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
	int nthUglyNumber(int n) {
		vector<int> dp(n, 0);
		dp[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
			if (dp[i] == dp[i2] * 2)
				i2++;
			if (dp[i] == dp[i3] * 3)
				i3++;
			if (dp[i] == dp[i5] * 5)
				i5++;
		}
		return dp[n - 1];
	}
};
#endif // ___Ugly_Number_II_264_h___
