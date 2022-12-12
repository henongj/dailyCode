
//https://leetcode.com/problems/pascals-triangle/?envType=study-plan&id=dynamic-programming-i
// 118. Pascal's Triangle

#ifndef ___Pascal_s_Triangle_118_h___
#define ___Pascal_s_Triangle_118_h___
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


template<typename T>
void print_2D_vector(vector<vector<T>>& matrix)
{
	for (auto i : matrix)
	{
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}
}
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows, vector<int>());

		for (int row = 0; row < numRows; row++)
		{
			result[row].resize(row + 1);
			result[row][0] = 1;
			result[row][row] = 1;

			for (int col = 1; col < row; col++)
				result[row][col] = result[row - 1][col - 1] + result[row - 1][col];
		}
		//		print_2D_vector(result);
		return result;
	}
};
#endif // ___Pascal_s_Triangle_118_h___