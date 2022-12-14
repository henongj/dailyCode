
//https://leetcode.com/problems/range-sum-query-2d-immutable/?envType=study-plan&id=dynamic-programming-i
//304. Range Sum Query 2D - Immutable
#ifndef ___Range_Sum_Query_2D_Immutable_304_h___
#define ___Range_Sum_Query_2D_Immutable_304_h___
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

class NumMatrix {
public:
	vector<vector<int>> memo;
	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		memo = vector<vector<int>>(m, vector<int>(n, 0));
		for (int r = 0; r < m; r++)
		{
			for (int c = 0; c < n; c++)
			{
				r == 0 ? memo[r][c] = matrix[r][c] : memo[r][c] = memo[r - 1][c] + matrix[r][c];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		int sum = 0;
		for (int c = col1; c <= col2; c++)
		{
			sum += memo[row2][c] - (row1 == 0 ? 0 : memo[row1 - 1][c]);
		}
		return sum;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif // ___Range_Sum_Query_2D_Immutable_304_h___