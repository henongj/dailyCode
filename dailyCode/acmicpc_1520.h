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

//https://www.acmicpc.net/problem/1520
//내리막 길
namespace acmicpc_1520
{
	using namespace std;

	void solution(void);
	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap);
	void DFS(int nRow, int nColumn, vector<vector<int>>& vvMap, vector<vector<int>>& vvMemo);
	bool isInside(pair<int, int> pPos, vector<vector<int>>& vvMap);
	void solution(void)
	{
		int nRow{};
		int nColumn{};
		vector<vector<int>> vvMap{};
		vector<vector<int>> vvMemo{};

		inputData(nRow, nColumn, vvMap);

		vvMemo.resize(nRow);
		for (int i = 0; i < nRow; ++i)
		{
			vvMemo[i].resize(nColumn, -1);
		}

		DFS(0, 0, vvMap, vvMemo);

		cout << vvMemo[0][0] << endl;


	}

	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap)
	{
		cin >> nRow;
		cin >> nColumn;

		vvMap.resize(nRow);
		for (int i = 0; i < nRow; ++i)
		{
			vvMap[i].resize(nColumn);
			for (int j = 0; j < nColumn; ++j)
			{
				cin >> vvMap[i][j];
			}
		}
	}

	void DFS(int nRow, int nColumn, vector<vector<int>>& vvMap, vector<vector<int>>& vvMemo)
	{
		if (!isInside({ nRow, nColumn }, vvMap))
			return;

		if (nRow == vvMap.size() - 1 && nColumn == vvMap[0].size() - 1)
		{
			vvMemo[nRow][nColumn] = 1;
			return;
		}

		if (vvMemo[nRow][nColumn] != -1)
			return;

		int arrDir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		int nCount{};

		nCount = 0;

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> pPosNext{ nRow + arrDir[i][0], nColumn + arrDir[i][1] };

			if (isInside(pPosNext, vvMap) && vvMap[nRow][nColumn] > vvMap[pPosNext.first][pPosNext.second])
			{
				DFS(pPosNext.first, pPosNext.second, vvMap, vvMemo);
				nCount += vvMemo[pPosNext.first][pPosNext.second];
			}

		}

		vvMemo[nRow][nColumn] = nCount;

	}

	bool isInside(pair<int, int> pPos, vector<vector<int>>& vvMap)
	{
		if (pPos.first >= 0 && pPos.first < vvMap.size() && pPos.second >= 0 && pPos.second < vvMap[0].size())
			return true;

		return false;
	}

}
