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
#include <limits>

//https://www.acmicpc.net/problem/1106
//호텔 

void dataInput_acmicpc1106(int& nC, int& nN, std::vector<std::pair<int, int>>& vCostInfo);
void solution_acmicpc1106(void);

int mainSpace01_acmicpc1106(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	solution_acmicpc1106();

	return 0;
}


void dataInput_acmicpc1106(int& nC, int& nN, std::vector<std::pair<int, int>>& vCostInfo)
{
	std::cin >> nC >> nN;
	vCostInfo.resize(nN);
	for (int i = 0; i < nN; ++i)
		std::cin >> vCostInfo[i].first >> vCostInfo[i].second;
}

void solution_acmicpc1106(void)
{
	int nC{};
	int nN{};
	std::vector<std::pair<int, int>> vCostInfo{};

	dataInput_acmicpc1106(nC, nN, vCostInfo);

	int* arrTotalCost{};
	int nArrLength = nC * 100 + 1;
	arrTotalCost = new int[nArrLength] {};
	arrTotalCost[0] = 0;

	for (int nTotalCustomer = 1; nTotalCustomer < nArrLength; nTotalCustomer++)
	{
		int nNextTotalCost = 210000000; // 좋지 않음

		for (int i = 0; i < nN; i++)
		{
			if (nTotalCustomer >= vCostInfo[i].second)
				nNextTotalCost = std::min(nNextTotalCost, arrTotalCost[nTotalCustomer - vCostInfo[i].second] + vCostInfo[i].first);
		}
		arrTotalCost[nTotalCustomer] = nNextTotalCost;
	}

	int nNumber = arrTotalCost[nC];
	for (int i = nC; i < nArrLength; i++)
	{
		if (nNumber > arrTotalCost[i])
			nNumber = arrTotalCost[i];
	}

	std::cout << nNumber;

	delete[] arrTotalCost;
}
