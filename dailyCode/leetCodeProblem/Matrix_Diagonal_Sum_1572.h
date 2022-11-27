
//https://leetcode.com/problems/matrix-diagonal-sum/?envType=study-plan&id=programming-skills-i
//1572. Matrix Diagonal Sum
#ifndef ___Matrix_Diagonal_Sum_1572_h___
#define ___Matrix_Diagonal_Sum_1572_h___
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
	int diagonalSum(vector<vector<int>>& mat) {
		pair<int, int> start1 = { 0, 0 };
		pair<int, int> start2 = { 0, mat[0].size() - 1 };
		int sum = 0;
		while (start1.first < mat.size() && 0 <= start2.first)
		{
			sum += mat[start1.first][start1.second];
			sum += mat[start2.first][start2.second];
			if (start1.first == start2.first && start1.second == start2.second)
				sum -= mat[start1.first][start1.second];
			start1.first++; start1.second++;
			start2.first++; start2.second--;
		}
		return sum;
	}
};

#endif // !___Matrix_Diagonal_Sum_1572_h___