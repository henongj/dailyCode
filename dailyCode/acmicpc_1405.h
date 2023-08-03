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

//https://www.acmicpc.net/problem/1405
//¹ÌÄ£ ·Îº¿

namespace acmicpc_1405
{
	void solutionAcmicpc1405();
	double dfs(int nRow, int nCol, int nMoveCount, int nMove, const std::vector<double>& vPercent, std::vector<std::vector<bool>>& vvVisited);

	int mainSpace01(void)
	{
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		solutionAcmicpc1405();

		return 0;
	}

	void solutionAcmicpc1405()
	{
		using namespace std;

		int nMove;
		vector<double> vPercent(4);
		vector<vector<bool>> vvVisited;

		cin >> nMove;

		vPercent.reserve(4);
		vvVisited.resize(nMove * 2 + 1, vector<bool>(nMove * 2 + 1, false));

		for (int i = 0; i < 4; ++i)
		{
			cin >> vPercent[i];
			vPercent[i] /= 100;
		}

		cout.precision(10);
		cout << dfs(nMove, nMove, nMove, nMove, vPercent, vvVisited) << endl;
	}

	double dfs(int nRow, int nCol, int nMoveCount, int nMove, const std::vector<double>& vPercent, std::vector<std::vector<bool>>& vvVisited)
	{
		if (nMoveCount == 0)
			return 1.0;

		double dRet{};
		vvVisited[nRow][nCol] = true;

		if (nRow > 0 && !vvVisited[nRow - 1][nCol])
			dRet += dfs(nRow - 1, nCol, nMoveCount - 1, nMove, vPercent, vvVisited) * vPercent[0];
		if (nRow < nMove * 2 && !vvVisited[nRow + 1][nCol])
			dRet += dfs(nRow + 1, nCol, nMoveCount - 1, nMove, vPercent, vvVisited) * vPercent[1];
		if (nCol > 0 && !vvVisited[nRow][nCol - 1])
			dRet += dfs(nRow, nCol - 1, nMoveCount - 1, nMove, vPercent, vvVisited) * vPercent[2];
		if (nCol < nMove * 2 && !vvVisited[nRow][nCol + 1])
			dRet += dfs(nRow, nCol + 1, nMoveCount - 1, nMove, vPercent, vvVisited) * vPercent[3];

		vvVisited[nRow][nCol] = false;

		return dRet;
	}
}