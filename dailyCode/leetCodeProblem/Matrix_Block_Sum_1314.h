//https://leetcode.com/problems/matrix-block-sum/?envType=study-plan&id=dynamic-programming-i
//1314. Matrix Block Sum
#ifndef ___Matrix_Block_Sum_1314_h___
#define ___Matrix_Block_Sum_1314_h___
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
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();

		vector<vector<int>> memo(m, vector<int>(n, 0));
		auto is_inside = [](const vector<vector<int>>& memo, const pair<int, int>& pos) -> bool { return (pos.first > memo.size() || pos.second > memo[0].size() || pos.first < 0 || pos.second < 0) ? false : true;  };

		// memo[r][c] 는 mat[0][c] 부터 mat[r][c] 까지의 누적 합
		for (int r = 0; r < m; r++)
		{
			for (int c = 0; c < n; c++)
			{
				r == 0 ? memo[r][c] = mat[r][c] : memo[r][c] = memo[r - 1][c] + mat[r][c];
			}
		}

		//print memo
		for (int r = 0; r < m; r++)
		{
			for (int c = 0; c < n; c++)
				cout << memo[r][c] << " ";
			cout << endl;
		}

		// answer[r][c]는 mat[r-k][c-k] 부터 mat[r+k][c+k] 까지의 합
		vector<vector<int>> answer(m, vector<int>(n, 0));

		for (int r = 0; r < m; r++)
		{
			for (int c = 0; c < n; c++)
			{
				// out of ranged라면, 최소나 최대값으로 보정
				int y_start = (r - k) < 0 ? 0 : r - k;
				int y_end = (r + k) >= m ? m - 1 : r + k;
				int x_start = (c - k) < 0 ? 0 : c - k;
				int x_end = (c + k) >= n ? n - 1 : c + k;

				// mat[y_start,x_start] ~ mat[y_end, x_end] 까지의 합 = (memo[y_end][x_start] ~ memo[y_end][x_end]) - (memo[y_start-1][x_start] ~ memo[y_start-1][x_end])
				// 단 y_start-1 < 0 일 경우 뺄 값이 없다
				for (int x = x_start; x <= x_end; x++)
					answer[r][c] += memo[y_end][x] - (y_start - 1 < 0 ? 0 : memo[y_start - 1][x]);

			}
		}


		return answer;
	}
};
#endif // ___Matrix_Block_Sum_1314_h___