#pragma once
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
#include<cmath>
#include<set>
#include <fstream>
#include<functional>
//https://www.acmicpc.net/problem/2580
//½ºµµÄí
namespace acmicpc_2580
{
	using namespace std;

	void solved(void);
	void printBoard();
	void dfs(int cnt);

	int board[9][9];
	bool row[9][10];
	bool col[9][10];
	bool square[9][10];

	void solved(void)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cin >> board[i][j];
				if (board[i][j] != 0)
				{
					row[i][board[i][j]] = true;
					col[j][board[i][j]] = true;
					square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
				}
			}
		}
		dfs(0);
	}

	void printBoard()
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << board[i][j] << " ";
			cout << endl;
		}
	}

	void dfs(int cnt)
	{
		if (cnt == 81)
		{
			printBoard();
			exit(0);
		}

		int x = cnt / 9;
		int y = cnt % 9;

		if (board[x][y] != 0)
		{
			dfs(cnt + 1);
		}
		else
		{
			for (int i = 1; i <= 9; ++i)
			{
				if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
				{
					row[x][i] = true;
					col[y][i] = true;
					square[(x / 3) * 3 + (y / 3)][i] = true;
					board[x][y] = i;
					dfs(cnt + 1);
					board[x][y] = 0;
					row[x][i] = false;
					col[y][i] = false;
					square[(x / 3) * 3 + (y / 3)][i] = false;
				}
			}
		}
	}
}

