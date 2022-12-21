
//https://leetcode.com/problems/perfect-squares/?envType=study-plan&id=dynamic-programming-i
//279. Perfect Squares
#ifndef ___Perfect_Squares_279_h___
#define ___Perfect_Squares_279_h___
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
	int numSquares(int n) {
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			dp[i] = i;
			for (int j = 1; j * j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};

#endif // ___Perfect_Squares_279_h___