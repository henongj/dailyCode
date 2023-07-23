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

//https://www.acmicpc.net/problem/1620
//나는야 포켓몬 마스터 이다솜
namespace acmicpc_1620
{
	void solution_acmicpc1620(void);
	void inputData_acmicpc1620(std::map<std::string, int>& mapData, std::map<int, const std::string*>& mapData2, int& nNumOfPocketMon, int& nNumOfQuestion);

	int mainSpace01_acmicpc1620(void)
	{
		/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/

		solution_acmicpc1620();

		return 0;
	}

	void solution_acmicpc1620(void)
	{
		//tie
		std::cin.tie(NULL);
		std::ios_base::sync_with_stdio(false);
		int nNumOfPocketMon{};
		int nNumOfQuestion{};
		std::map<std::string, int> mapData{};
		std::map<int, const std::string*> mapData2{};

		inputData_acmicpc1620(mapData, mapData2, nNumOfPocketMon, nNumOfQuestion);

		for (int i = 0; i < nNumOfQuestion; ++i)
		{
			std::string strQuestion{};
			std::cin >> strQuestion;
			if (strQuestion[0] >= '0' && strQuestion[0] <= '9')
			{
				std::map<int, const std::string*>::iterator iter = mapData2.find(std::stoi(strQuestion));
				std::cout << *iter->second << "\n";
			}
			else
			{
				std::map<std::string, int>::iterator iter = mapData.find(strQuestion);
				std::cout << iter->second << "\n";
			}

		}
	}

	void inputData_acmicpc1620(std::map<std::string, int>& mapData, std::map<int, const std::string*>& mapData2, int& nNumOfPocketMon, int& nNumOfQuestion)
	{
		std::cin >> nNumOfPocketMon;
		std::cin >> nNumOfQuestion;
		int nPocketMonNumber{};

		nPocketMonNumber = 1;
		for (int i = 0; i < nNumOfPocketMon; ++i)
		{
			std::string strPocketMon{};
			std::cin >> strPocketMon;

			std::map<std::string, int>::iterator iter{};
			iter = mapData.insert({ strPocketMon, nPocketMonNumber }).first;
			mapData2.emplace(nPocketMonNumber, &iter->first);

			nPocketMonNumber++;
		}

	}
}
