//200. Number of Islands
#ifndef ___Number_of_Islands_200_h___
#define ___Number_of_Islands_200_h___
// https://leetcode.com/problems/number-of-islands/
#include<iostream>
#include<vector>
#include<string>
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
#endif
