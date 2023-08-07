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
#include <fstream>
#include<functional>

//https://www.acmicpc.net/problem/1987
//¾ËÆÄºª 
namespace acmicpc_1987
{
	void solution_acmicpc1987(void);
	void inputData_acmicpc1987(int& nRow, int& nColumn, std::vector<std::string>& vMap);
	void DFS(std::vector<std::string>& vMap, std::pair<int, int> pPosition, int nCount, int& nMaxCount, std::vector<bool>& vAlphabetCheck);
	int mainSpace_acmicpc1987(void)
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		solution_acmicpc1987();

		return 0;
	}

	void solution_acmicpc1987(void)
	{
		int nRow{};
		int nColumn{};
		std::vector<std::string> vMap{};
		std::vector<bool> vAlphabetCheck(26, false);
		int nMaxCount{};

		inputData_acmicpc1987(nRow, nColumn, vMap);
		DFS(vMap, { 0,0 }, 0, nMaxCount, vAlphabetCheck);

		std::cout << nMaxCount << "\n";
	}

	void inputData_acmicpc1987(int& nRow, int& nColumn, std::vector<std::string>& vMap)
	{
		using namespace std;

		cin >> nRow;
		cin >> nColumn;

		vMap.reserve(20);

		for (int i = 0; i < nRow; ++i)
		{
			string str{};
			str.reserve(20);
			cin >> str;
			vMap.push_back(str);
		}
	}

	void DFS(std::vector<std::string>& vMap, std::pair<int, int> pPosition, int nCount, int& nMaxCount, std::vector<bool>& vAlphabetCheck)
	{
		using namespace std;

		int nRow = pPosition.first;
		int nColumn = pPosition.second;
		int arrDir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

		if (nRow < 0 || nRow >= vMap.size() || nColumn < 0 || nColumn >= vMap[0].size())
			return;
		if (vAlphabetCheck[vMap[nRow][nColumn] - 'A'])
			return;

		vAlphabetCheck[vMap[nRow][nColumn] - 'A'] = true;
		nCount++;
		nMaxCount = max(nMaxCount, nCount);

		for (int i = 0; i < 4; i++)
		{
			DFS(vMap, { nRow + arrDir[i][0], nColumn + arrDir[i][1] }, nCount, nMaxCount, vAlphabetCheck);
		}

		vAlphabetCheck[vMap[nRow][nColumn] - 'A'] = false;
		nColumn--;


	}
}
