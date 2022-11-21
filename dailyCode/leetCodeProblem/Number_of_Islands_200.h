//200. Number of Islands
#ifndef ___Number_of_Islands_200_h___
#define ___Number_of_Islands_200_h___
// https://leetcode.com/problems/number-of-islands/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
	void erase_island(vector<vector<char>>& grid, int ypos, int xpos)
	{
		// 물이면 돌아간다
		if (grid[ypos][xpos] == '0')
			return;

		grid[ypos][xpos] = '0';

		// 상하좌우를 검사한다
		auto is_inside = [&](int ypos, int xpos) -> bool
		{
			if (ypos < 0 || ypos >= grid.size() || xpos < 0 || xpos >= grid[0].size())
				return false;
			return true;
		};

		if (is_inside(ypos + 1, xpos))
			erase_island(grid, ypos + 1, xpos);
		if (is_inside(ypos - 1, xpos))
			erase_island(grid, ypos - 1, xpos);
		if (is_inside(ypos, xpos + 1))
			erase_island(grid, ypos, xpos + 1);
		if (is_inside(ypos, xpos - 1))
			erase_island(grid, ypos, xpos - 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for (int ypos = 0; ypos < grid.size(); ypos++) {
			for (int xpos = 0; xpos < grid[ypos].size(); xpos++) {
				if (grid[ypos][xpos] == '1') {
					count++;
					erase_island(grid, ypos, xpos);
				}
			}
		}
		return count;
	}
	
};

class Solution2 {
public:
	int numIslands(vector<vector<char>>& grid) {
		// Use BFS
		queue<pair<int, int>> q;
		int count = 0;
		for (int ypos = 0; ypos < grid.size(); ypos++) {
			for (int xpos = 0; xpos < grid[ypos].size(); xpos++) {
				if (grid[ypos][xpos] == '1') {
					count++;
					q.push({ ypos, xpos });
					while (!q.empty()) {
						auto [ypos, xpos] = q.front();
						q.pop();
						if (grid[ypos][xpos] == '0')
							continue;
						grid[ypos][xpos] = '0';
						if (ypos + 1 < grid.size())
							q.push({ ypos + 1, xpos });
						if (ypos - 1 >= 0)
							q.push({ ypos - 1, xpos });
						if (xpos + 1 < grid[ypos].size())
							q.push({ ypos, xpos + 1 });
						if (xpos - 1 >= 0)
							q.push({ ypos, xpos - 1 });
					}
				}
			}
		}
	}
};
#endif
