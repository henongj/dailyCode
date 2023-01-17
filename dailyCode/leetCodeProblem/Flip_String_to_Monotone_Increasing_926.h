//https://leetcode.com/problems/flip-string-to-monotone-increasing/
//926. Flip String to Monotone Increasing
#ifndef ___Flip_String_to_Monotone_Increasing_926_h___
#define ___Flip_String_to_Monotone_Increasing_926_h___
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
#include<cmath>	
using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int n = s.size();
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + (s[i - 1] == '1' ? 1 : 0);
		}
		int res = INT_MAX;
		for (int i = 0; i <= n; i++) {
			res = min(res, dp[i] + n - i - (dp[n] - dp[i]));
		}
		return res;
	}
};
#endif // ___Flip_String_to_Monotone_Increasing_926_h___