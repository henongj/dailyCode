
//419. ___Battleships_in_a_Board_419_h___
//https://leetcode.com/problems/battleships-in-a-board/
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
	void search_battle_ship(vector<vector<char>>& board, int ypos, int xpos)
	{
		board[ypos][xpos] = '.';

		vector<vector<int>> direction = { {0,1},{0,-1},{-1,0},{1,0} };
		for (int i = 0; i < 4; i++)
		{
			int y = ypos + direction[i][0];
			int x = xpos + direction[i][1];

			if (!(y < 0 || y >= board.size() || x < 0 || x >= board[0].size()))
			{
				if (board[y][x] == 'X')
					search_battle_ship(board, y, x);
			}
		}
	}
	int countBattleships(vector<vector<char>>& board) {
		int ypos, xpos;
		int count = 0;
		for (ypos = 0; ypos < board.size(); ypos++)
		{
			for (xpos = 0; xpos < board[0].size(); xpos++)
			{
				if (board[ypos][xpos] == 'X')
				{
					count++;
					search_battle_ship(board, ypos, xpos);
				}
			}
		}
		return count;
	}
};