#pragma once
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
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
//https://www.acmicpc.net/problem/1229
//육각수
namespace acmicpc_1229_wrongAnswer
{
	void solution_acmicpc1229(void);
	void inputData_acmicpc1229(int& nNumber);
	void generateHexagonNumber(std::vector<int>& vHexagonTable, int nRange);



	int mainSpace01(void)
	{
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		solution_acmicpc1229();

		return 0;
	}

	void solution_acmicpc1229(void)
	{
		int nNumber{};
		const int nRangeHexagonNumber = 146858;
		const int nRangeAnswer = 1000000;
		std::vector<int> vHexagonTable{};
		int* nMemo{};
		nMemo = new int[nRangeAnswer + 1] {};

		inputData_acmicpc1229(nNumber);
		generateHexagonNumber(vHexagonTable, nRangeHexagonNumber);

		for (int i = 0; i < vHexagonTable.size(); i++)
		{
			int nTemp = vHexagonTable[i];
			int nCount = 1;
			while (nTemp <= nRangeAnswer)
			{
				nMemo[nTemp] = nCount;
				nCount++;
				nTemp += vHexagonTable[i];
			}
		}

		for (int i = 1; i <= nNumber; i++)
		{//다시짜야함
			int nIndex = i;
			int nTemp = i;
			int nCount = 0;
			int nPick = vHexagonTable.size() - 1;
			while (0 < nTemp)
			{
				if (0 <= nTemp - vHexagonTable[nPick])
				{
					nTemp = nTemp - vHexagonTable[nPick];
					nCount++;
					nPick++;
				}
				nPick--;
			}
			nMemo[nIndex] = std::min(nCount, nMemo[nIndex]);
		}



		std::cout << nMemo[nNumber - 1] << "\n";


		delete[] nMemo;
	}

	void inputData_acmicpc1229(int& nNumber)
	{
		std::cin >> nNumber;
	}

	void generateHexagonNumber(std::vector<int>& vHexagonTable, int nRange)
	{
		vHexagonTable.reserve(1000);

		int nHexagonNumber{};
		int nHexagonNumberPrev{};

		nHexagonNumber = 1;
		nHexagonNumberPrev = 0;
		for (int i = 1; true; i++)
		{
			nHexagonNumber = nHexagonNumberPrev + (i * 4) - 3;
			vHexagonTable.push_back(nHexagonNumber);

			nHexagonNumberPrev = nHexagonNumber;
			if (nHexagonNumber > nRange)
				break;
		}
	}

}
