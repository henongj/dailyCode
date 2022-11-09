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
		{ // ����� �ϴ� ����� ���ٸ� trust_mapping���� ����
			if (!trust_mapping.count(trust_mapping[i])) // �ϴ� ����� ���� ���
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
		//�湮üũ // ���� �ٲ����
		grid[ypos][xpos] = '0';

		vector<vector<int>> movePos = { {-1,0},{1,0},{0,-1},{0,1} };

		for (int i = 0; i < movePos.size(); i++)
		{
			int x = xpos + movePos[i][0];
			int y = ypos + movePos[i][1];
			// ������ ���� ��ǥ ���̸鼭, '1'�̸� ��� Ž��
			if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == '0')
				return;
			visite_new_island(grid, y, x);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;

		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[0].size(); col++)
			{// ���ε�, �湮�� �� ������
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
