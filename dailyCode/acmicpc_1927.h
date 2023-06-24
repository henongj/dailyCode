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

//https://www.acmicpc.net/problem/1927
//ÃÖ¼Ò Èü
void solution_acmicpc1927(void);

int mainSapce01_acmicpc1927(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution_acmicpc1927();

	return 0;
}


void solution_acmicpc1927(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> vData{};
	int nLength{};

	std::priority_queue<int, std::vector<int>, std::greater<int>> pqData{};
	std::cin >> nLength;

	for (int i = 0; i < nLength; i++)
	{
		int nTemp{};
		std::cin >> nTemp;

		if (nTemp == 0)
		{
			if (pqData.empty())
				std::cout << "0\n";
			else
			{
				std::cout << pqData.top() << "\n";
				pqData.pop();
			}
		}
		else
			pqData.push(nTemp);
	}

}
