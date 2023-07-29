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


//https://www.acmicpc.net/problem/14940
//쉬운 최단거리
namespace acmicpc_14940{

	void solution_acmicpc14940(void);
	void inputData(int& nRow, int& nColumn, std::vector<std::vector<int>>& vvMap, std::pair<int, int>& pStart);
	bool isInside(const std::vector<std::vector<int>>& vvMap, const std::pair<int, int>& pPos);

	int mainSpace_acmicpc14940(void)
	{


		solution_acmicpc14940();

		return 0;
	}


	void solution_acmicpc14940(void)
	{
		int nRow{};
		int nColumn{};
		std::vector<std::vector<int>> vvMap{};
		std::vector<std::vector<bool>> vvCheck{};
		std::pair<int, int> pStart;
		std::vector<std::vector<int>> vvResult{};
		int arrDir[4][2]{ {0,1},{0,-1},{1,0},{-1,0} };

		inputData(nRow, nColumn, vvMap, pStart);
		vvResult.resize(nRow, std::vector<int>(nColumn, 0));
		vvCheck.resize(nRow, std::vector<bool>(nColumn, false));

		std::queue<std::tuple<int, int, int>> qBFS{}; //xpos, ypos, distance

		std::tuple<int, int, int> tPos{ pStart.first, pStart.second, 0 };
		qBFS.push({ tPos });
		vvCheck[pStart.first][pStart.second] = true;

		while (!qBFS.empty())
		{
			tPos = qBFS.front();
			int nRow = std::get<0>(tPos);
			int nColumn = std::get<1>(tPos);
			int nDistance = std::get<2>(tPos);
			qBFS.pop();


			if (!vvMap[nRow][nColumn])
				vvResult[nRow][nColumn] = 0;
			else
				vvResult[nRow][nColumn] = nDistance;

			for (int i = 0; i < 4; i++)
			{
				int nNextRow = nRow + arrDir[i][0];
				int nNextColumn = nColumn + arrDir[i][1];
				int nNextDistance = nDistance + 1;
				//std::cout << nNextRow << ", " << nNextColumn << "\n";

				if (isInside(vvMap, { nNextRow, nNextColumn }) && vvCheck[nNextRow][nNextColumn] == false)
				{
					if (vvMap[nNextRow][nNextColumn])
						qBFS.push({ nNextRow, nNextColumn, nNextDistance });
					vvCheck[nNextRow][nNextColumn] = true;
				}
			}
		}

		for (int i = 0; i < nRow; i++)
		{
			for (int j = 0; j < nColumn; j++)
			{
				if (vvMap[i][j] == 0)
					vvResult[i][j] = 0;
				else if (vvCheck[i][j] == false)
					vvResult[i][j] = -1;
			}
		}

		for (int i = 0; i < nRow; i++)
		{
			for (int j = 0; j < nColumn; j++)
			{
				std::cout << vvResult[i][j] << " ";
			}
			std::cout << "\n";
		}

	}

	void inputData(int& nRow, int& nColumn, std::vector<std::vector<int>>& vvMap, std::pair<int, int>& pStart)
	{
		std::cin >> nRow;
		std::cin >> nColumn;

		vvMap.resize(nRow);
		for (int i = 0; i < nRow; i++)
		{
			vvMap[i].resize(nColumn);
			for (int j = 0; j < nColumn; j++)
			{
				std::cin >> vvMap[i][j];
				if (vvMap[i][j] == 2)
				{
					pStart.first = i;
					pStart.second = j;
				}
			}
		}
	}

	bool isInside(const std::vector<std::vector<int>>& vvMap, const std::pair<int, int>& pPos)
	{
		if (pPos.first < 0 || pPos.first >= vvMap.size())
			return false;
		if (pPos.second < 0 || pPos.second >= vvMap[0].size())
			return false;

		return true;

	}


}
