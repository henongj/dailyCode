#ifndef ___Max_Area_of_Island_695___
#define ___Max_Area_of_Island_695___
//695. Max Area of Island
//https://leetcode.com/problems/max-area-of-island/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int helper(vector<vector<int>>& grid, int ypos, int xpos)
	{
		if (ypos < 0 || ypos >= grid.size() || xpos < 0 || xpos >= grid[0].size() || grid[ypos][xpos] == 0)
			return 0;
		grid[ypos][xpos] = 0;
		return 1 + helper(grid, ypos - 1, xpos) + helper(grid, ypos + 1, xpos) + helper(grid, ypos, xpos - 1) + helper(grid, ypos, xpos + 1);
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					int area = helper(grid, i, j);
					maxArea = max(maxArea, area);
				}
			}
		}
		return maxArea;
	}
};
#endif