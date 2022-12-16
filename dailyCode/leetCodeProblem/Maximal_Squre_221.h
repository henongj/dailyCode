
//https://leetcode.com/problems/maximal-square/description/?envType=study-plan&id=dynamic-programming-i
//221. Maximal Square
#ifndef ___Maximal_Squre_221_h___
#define ___Maximal_Squre_221_h___
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
	int maximalSquare(vector<vector<char>>& matrix) {

		if (matrix.empty() || matrix[0].empty())
			return 0;

		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		int maxLen = 0;

		for (int i = 0; i < m; ++i) {
			dp[i][0] = matrix[i][0] - '0';
			maxLen = max(maxLen, dp[i][0]);
		}
		for (int j = 0; j < n; ++j) {
			dp[0][j] = matrix[0][j] - '0';
			maxLen = max(maxLen, dp[0][j]);
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					maxLen = max(maxLen, dp[i][j]);
				}
			}
		}
		return maxLen * maxLen;
	}
};


#endif // ___Maximal_Squre_221_h___