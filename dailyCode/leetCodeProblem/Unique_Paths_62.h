
//https://leetcode.com/problems/unique-paths/
//62. Unique Paths
#ifndef ___Unique_Paths_62_h___
#define ___Unique_Paths_62_h___
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
	void recursion(vector<vector<int>>& memo, int row, int col)
	{
		if (row < 0 || col < 0)
			return;

		if (row == 0 && col == 0)
		{
			memo[row][col] = 1;
			return;
		}
		recursion(memo, row - 1, col);
		recursion(memo, row, col - 1);

		if (col == 0)
			memo[row][col] = memo[row - 1][col];
		if (row == 0)
			memo[row][col] = memo[row][col - 1];
		if (row > 0 && col > 0)
			memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
	}
	int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n, 0));
		recursion(memo, m - 1, n - 1);
		return memo[m - 1][n - 1];
	}

	int uniquePaths_loop(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			memo[i][0] = 1;
		for (int i = 0; i < n; i++)
			memo[0][i] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			}
		}

		return memo[m - 1][n - 1];

	}
};
#endif // ___Unique_Paths_62_h___