
//https://leetcode.com/problems/minimum-falling-path-sum/
//931. Minimum Falling Path Sum
#ifndef ___Minimum_Falling_Path_Sum_931_h___
#define ___Minimum_Falling_Path_Sum_931_h___
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

// make template function which print matrix of vector
template<typename T>
void printMatrix(vector<vector<T>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {

		int n = matrix.size();

		// make dp matrix
		vector<vector<int>> dp(n, vector<int>(n, 0));

		// copy first row of matrix to dp matrix
		for (int i = 0; i < n; i++) {
			dp[0][i] = matrix[0][i];
		}

		// fill dp matrix
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0)
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
				else if (j == n - 1)
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
				else
					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + matrix[i][j];
			}
		}

		// find minimum value in last row of dp matrix
		int min = dp[n - 1][0];
		for (int i = 1; i < n; i++) {
			if (min > dp[n - 1][i]) {
				min = dp[n - 1][i];
			}
		}

		return min;

	}
};


#endif // ___Minimum_Falling_Path_Sum_931_h___