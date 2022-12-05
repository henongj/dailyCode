
//https://leetcode.com/problems/minimum-path-sum/
//64. Minimum Path Sum
#ifndef ___Minimum_Path_Sum_64_h___
#define ___Minimum_Path_Sum_64_h___
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

// make function to copy vector<vector<int>> 
vector<vector<int>> copyVector(vector<vector<int>>& grid) {
	vector<vector<int>> copyGrid;
	for (int i = 0; i < grid.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < grid[i].size(); j++) {
			temp.push_back(grid[i][j]);
		}
		copyGrid.push_back(temp);
	}
	return copyGrid;
}

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<vector<int>> memo = copyVector(grid);
		int row_len = grid.size();
		int col_len = grid[0].size();
		memo[0][0] = grid[0][0];

		for (int i = 1; i < row_len; i++) {
			memo[i][0] = memo[i - 1][0] + grid[i][0];
		}
		for (int j = 1; j < col_len; j++) {
			memo[0][j] = memo[0][j - 1] + grid[0][j];
		}

		for (int row = 1; row < row_len; row++) {
			for (int col = 1; col < col_len; col++) {
				memo[row][col] = min(memo[row - 1][col], memo[row][col - 1]) + grid[row][col];
			}
		}

		return memo[row_len - 1][col_len - 1];
	}
};
#endif // ___Minimum_Path_Sum_64_h___
