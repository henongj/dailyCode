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

//https://www.acmicpc.net/problem/1241
//∏”∏Æ ≈Â≈Â
void solution_acmicpc1241(void);
void dataInput_acmicpc1241(int& nLength, std::vector<std::pair<int, std::vector<int>>>& vData);
void getDivisors(int nTarget, std::vector<int>& vResult);
int mainSpace01_acmicpc1241(void)
{
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/

	solution_acmicpc1241();


	return 0;
}

void solution_acmicpc1241(void)
{
	int nLength{};
	std::vector<std::pair<int, std::vector<int>>> vData;

	std::vector<int> vCount{};

	dataInput_acmicpc1241(nLength, vData);
	vCount.resize(1000000, 0);

	std::vector<int> vResult{};
	for (int i = 0; i < nLength; i++)
	{
		vCount[vData[i].first] = vCount[vData[i].first] + 1;
		getDivisors(vData[i].first, vData[i].second);
	}

	for (int i = 0; i < nLength; i++)
	{
		int nCount = 0;

		for (int j = 0; j < vData[i].second.size(); j++)
			nCount = nCount + vCount[vData[i].second[j]];

		vResult.push_back(nCount - 1);
	}



	for (int i = 0; i < nLength; i++)
		std::cout << vResult[i] << "\n";
}

void dataInput_acmicpc1241(int& nLength, std::vector<std::pair<int, std::vector<int>>>& vData)
{
	vData.clear();

	std::cin >> nLength;
	vData.reserve(nLength);
	std::vector<int> vDivisor{};

	for (int i = 0; i < nLength; i++)
	{
		int nTemp{};
		std::cin >> nTemp;
		vData.push_back({ nTemp, vDivisor });
	}

}

void getDivisors(int nTarget, std::vector<int>& vResult)
{
	vResult.clear();

	int i = 1;
	while (i * i <= nTarget)
	{
		if (nTarget % i == 0)
		{
			vResult.push_back(i);
			if (nTarget / i != i)
				vResult.push_back(nTarget / i);
		}
		i++;
	}
}
