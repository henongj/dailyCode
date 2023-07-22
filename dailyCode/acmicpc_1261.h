#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
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

//https://www.acmicpc.net/problem/1261
//알고스팟
namespace acmicpc_1261{
	void solution_acmicpc1261(void);
	void dataInput_acmicpc1261(int& nRow, int& nColumn, std::vector<std::string>& vvMap);
	bool isInside(int nYpos, int nXpos, std::vector<std::string>& vvMap);

	int mainSpace01(void)
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc1261();

		return 0;
	}

	void solution_acmicpc1261(void)
	{
		int nRow{};
		int nColumn{};
		std::vector<std::string> vvMap{};
		std::vector<std::vector<int>> vvCountBroken{};
		std::vector<std::vector<bool>> vvCheckVisit{};
		int vDirection[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

		dataInput_acmicpc1261(nRow, nColumn, vvMap);

		vvCheckVisit.resize(nRow, std::vector<bool>(nColumn, false));
		vvCountBroken.resize(nRow, std::vector<int>(nColumn, 0));

		std::queue<std::pair<int, int>> qPos{};
		qPos.push(std::make_pair(0, 0));
		vvCheckVisit[0][0] = true;
		vvCountBroken[0][0] = 0;


		while (!qPos.empty())
		{
			// 1. 탐색할때 push하려면 범위 안, 방문하지 않았거나, 방문한 곳인데 폭파한 벽 수가 더 많으면 push
			std::pair<int, int> pPosition = qPos.front();
			int nYpos = pPosition.first;
			int nXpos = pPosition.second;
			qPos.pop();

			for (int i = 0; i < 4; i++)
			{
				int nNextYpos = pPosition.first + vDirection[i][0];
				int nNextXpos = pPosition.second + vDirection[i][1];

				if (isInside(nNextYpos, nNextXpos, vvMap))
				{
					int nWallCount = vvCountBroken[nYpos][nXpos];
					if (vvMap[nNextYpos][nNextXpos] == '1')
						nWallCount++;

					if (!vvCheckVisit[nNextYpos][nNextXpos] || nWallCount < vvCountBroken[nNextYpos][nNextXpos])
					{
						qPos.push({ nNextYpos, nNextXpos });
						vvCountBroken[nNextYpos][nNextXpos] = nWallCount;
						vvCheckVisit[nNextYpos][nNextXpos] = true;
					}
				}
			}

		}

		std::cout << vvCountBroken[nRow - 1][nColumn - 1] << "\n";

	}

	void dataInput_acmicpc1261(int& nRow, int& nColumn, std::vector<std::string>& vvMap)
	{
		std::cin >> nColumn;
		std::cin >> nRow;
		std::cin.ignore();

		vvMap.reserve(nRow);
		for (int i = 0; i < nRow; i++)
		{
			std::string strData{};
			std::getline(std::cin, strData);

			vvMap.push_back(strData);
		}
	}

	bool isInside(int nYpos, int nXpos, std::vector<std::string>& vvMap)
	{
		if (nYpos < 0 || nYpos >= vvMap.size() || nXpos < 0 || nXpos >= vvMap[0].size())
			return false;

		return true;
	}
}
