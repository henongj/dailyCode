#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

/*
//997. find the town judge
//https://leetcode.com/problems/find-the-town-judge/
class Solution{
public:

    int findJudge(int n, vector<vector<int>>& trust) {
		
		int judge = -1;
		
		unordered_map<int, int> trust_mapping;
		
		for (auto i : trust) 
			trust_mapping[i[0]] = i[1];

		for (int i = 0; i < n; i++)
		{ // 대상이 믿는 사람이 없다면 trust_mapping에도 없다
			if (!trust_mapping.count(trust_mapping[i])) // 믿는 대상이 없을 경우
				return trust_mapping[i];
		}
		
		return judge;
    }
};
//797*/

/*
200. Number of Islands
___Number_of_Islands_200_h___
https://leetcode.com/problems/number-of-islands/

class Solution {
public:

	void visite_new_island(vector<vector<char>>& grid, int ypos, int xpos)
	{
		if (grid[ypos][xpos] == '0')
			return;
		cout << "ypos xpos " << ypos << " " << xpos << "\n";
		//방문체크 // 물로 바꿔버림
		grid[ypos][xpos] = '0';

		vector<vector<int>> movePos = { {-1,0},{1,0},{0,-1},{0,1} };

		for (int i = 0; i < movePos.size(); i++)
		{
			int x = xpos + movePos[i][0];
			int y = ypos + movePos[i][1];
			// 인접한 곳이 좌표 안이면서, '1'이면 계속 탐색
			if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == '0')
				return;
			visite_new_island(grid, y, x);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;

		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[0].size(); col++)
			{// 섬인데, 방문을 안 했으면
				if (grid[row][col] == '1')
				{
					cout << "grid : " << row << ", " << col << "\n";
					visite_new_island(grid, row,col);
					count++;
				}
			}
		return count;
	}
};
*/




int main(void)
{
	
	return 0;
}
