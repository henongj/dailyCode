//https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=programming-skills-i
//566. Reshape the Matrix
#ifndef ___Reshape_the_Matrix_566_h___
#define ___Reshape_the_Matrix_566_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		vector<vector<int>> result;
		if (mat.size() * mat[0].size() != r * c)
			return mat;

		vector<int> row;
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				row.push_back(mat[i][j]);
				if (row.size() == c)
				{
					result.push_back(row);
					row.clear();
				}
			}
		}

		return result;
	}
};


#endif // ___Reshape_the_Matrix_566_h___