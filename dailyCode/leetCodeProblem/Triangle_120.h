
//https://leetcode.com/problems/triangle/?envType=study-plan&id=dynamic-programming-i
//120. Triangle
#ifndef ___Triangle_120_h___
#define ___Triangle_120_h___
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
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				if (j == 0)
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				else if (j == triangle[i].size() - 1)
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
		int min = dp[n - 1][0];
		for (int i = 1; i < n; i++) {
			if (min > dp[n - 1][i])
				min = dp[n - 1][i];
		}
		return min;
	}
};
#endif // ___Triangle_120_h___
