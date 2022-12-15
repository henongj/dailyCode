
//https://leetcode.com/problems/unique-paths-ii/?envType=study-plan&id=dynamic-programming-i
//63. Unique Paths II
#ifndef ___Unique_Paths_II_63_h___
#define ___Unique_Paths_II_63_h___
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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] == 1) break;
			dp[i][0] = 1;
		}
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 1) break;
			dp[0][j] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
#endif // ___Unique_Paths_II_63_h___
