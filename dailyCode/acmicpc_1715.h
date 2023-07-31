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
#include<functional>

//https://www.acmicpc.net/problem/1715
//카드 정렬하기
namespace acmicpc_1715{
	void solution_acmicpc1715(void);
	void inputData_acmicpc1715(int& nNumber, std::priority_queue<int, std::vector<int>, std::greater<int>>& pqCard);

	int mainSpace01_acmicpc1715(void)
	{
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		solution_acmicpc1715();

		return 0;
	}

	void solution_acmicpc1715(void)
	{
		int nNumber{};
		int nResult{};
		std::priority_queue<int, std::vector<int>, std::greater<int>> pqCard{};
		inputData_acmicpc1715(nNumber, pqCard);

		nResult = 0;
		while (pqCard.size() > 1)
		{
			int nFirst = pqCard.top();
			pqCard.pop();
			int nSecond = pqCard.top();
			pqCard.pop();

			int nSum = nFirst + nSecond;
			nResult += nSum;
			pqCard.push(nSum);
		}

		std::cout << nResult << std::endl;
	}

	void inputData_acmicpc1715(int& nNumber, std::priority_queue<int, std::vector<int>, std::greater<int>>& pqCard)
	{
		std::cin >> nNumber;
		for (int i = 0; i < nNumber; i++)
		{
			int nCard = 0;
			std::cin >> nCard;
			pqCard.push(nCard);
		}
	}
}
