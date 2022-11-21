
//https://leetcode.com/problems/rotting-oranges/
// 994. Rotting Oranges
#ifndef ___Rotting_Oranges_994_h___
#define ___Rotting_Oranges_994_h___
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
	bool is_rotten_all(const vector<vector<int>>& grid)
	{
		for (auto row : grid)
		{
			for (auto orange : row)
			{
				if (orange == 1)
					return false;
			}
		}
		return true;
	}
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> q;
		const int empty = 0; const int fresh_orange = 1; const int rotten_orange = 2;
		int minute = 0;
		for (int row = 0; row < grid.size(); row++)
		{
			for (int col = 0; col < grid[row].size(); col++)
			{
				if (grid[row][col] == rotten_orange)
					q.push({ row,col });
			}
		}

		while (!q.empty())
		{
			if (is_rotten_all(grid))
				break;

			// 1분마다 모든 썩은 오렌지는 주변 4 방향 전파 해야함
			int one_miniute = q.size();
			minute++;
			cout << "min : " << minute << "\n";
			for (int cycle = 0; cycle < one_miniute; cycle++)
			{ // 하나의 썩은 오렌지의 전파 과정
				pair<int, int> pos = q.front();
				q.pop();
				if (pos.first + 1 < grid.size() && grid[pos.first + 1][pos.second] == fresh_orange)
				{
					grid[pos.first + 1][pos.second] = rotten_orange;
					q.push({ pos.first + 1 , pos.second });
				}
				if (pos.first - 1 >= 0 && grid[pos.first - 1][pos.second] == fresh_orange)
				{
					grid[pos.first - 1][pos.second] = rotten_orange;
					q.push({ pos.first - 1 , pos.second });
				}
				if (pos.second + 1 < grid[0].size() && grid[pos.first][pos.second + 1] == fresh_orange)
				{
					grid[pos.first][pos.second + 1] = rotten_orange;
					q.push({ pos.first , pos.second + 1 });
				}
				if (pos.second - 1 >= 0 && grid[pos.first][pos.second - 1] == fresh_orange)
				{
					grid[pos.first][pos.second - 1] = rotten_orange;
					q.push({ pos.first, pos.second - 1 });
				}
			}
		}

		return is_rotten_all(grid) ? minute : -1;
	}
};

#endif //___Rotting_Oranges_994_h___
