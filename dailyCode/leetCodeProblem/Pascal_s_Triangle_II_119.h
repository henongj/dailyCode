
//https://leetcode.com/problems/pascals-triangle-ii/?envType=study-plan&id=dynamic-programming-i
// 119. Pascal's Triangle II
#ifndef ___Pascal_s_Triangle_II_119_h___
#define ___Pascal_s_Triangle_II_119_h___
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
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> pascal_triangle(rowIndex + 1, vector<int>());
		for (int row = 0; row <= rowIndex; row++)
		{
			pascal_triangle[row].resize(row + 1);
			pascal_triangle[row][0] = 1;
			pascal_triangle[row][row] = 1;

			for (int col = 1; col < row; col++)
				pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + pascal_triangle[row - 1][col];
		}

		return pascal_triangle[rowIndex];
	}
};

#endif // ___Pascal_s_Triangle_II_119_h___
