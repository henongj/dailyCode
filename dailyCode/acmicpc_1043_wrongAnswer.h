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

//https://www.acmicpc.net/problem/1043
//°ÅÁþ¸»
void solution01_acmicpc1043(void);
void dataInput01_acmicpc1043(int& nNumOfPerson, int& nNumOfParty, std::vector<bool>& vTruthPerson, std::vector<std::vector<int>>& vParty);
bool isThereTruthPerson_acmicpc1043(std::vector<int>& vParty, const std::vector<bool>& vTruthPerson);
int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution01_acmicpc1043();

	return 0;
}

void solution01_acmicpc1043(void)
{
	int nNumOfPerson{};
	int nNumOfParty{};
	std::vector<bool> vTruthPerson{};
	std::vector<std::vector<int>> vParty{};

	dataInput01_acmicpc1043(nNumOfPerson, nNumOfParty, vTruthPerson, vParty);

	int nCount = nNumOfParty;

	for (int i = 0; i < vParty.size(); i++)
	{
		if (isThereTruthPerson_acmicpc1043(vParty[i], vTruthPerson))
		{
			for (int j = 0; j < vParty[i].size(); j++)
				vTruthPerson[vParty[i][j]] = true;
		}
	}

	for (int i = 0; i < vParty.size(); i++)
	{
		if (isThereTruthPerson_acmicpc1043(vParty[i], vTruthPerson))
		{
			nCount--;
		}
	}

	std::cout << nCount;
}

void dataInput01_acmicpc1043(int& nNumOfPerson, int& nNumOfParty, std::vector<bool>& vTruthPerson, std::vector<std::vector<int>>& vParty)
{
	int nTempLength{};
	std::cin >> nNumOfPerson;
	std::cin >> nNumOfParty;

	std::cin >> nTempLength;
	vTruthPerson.resize(nNumOfPerson + 1, false);
	for (int i = 0; i < nTempLength; ++i)
	{
		int nTemp{};
		std::cin >> nTemp;
		vTruthPerson[nTemp] = true;
	}

	vParty.reserve(nNumOfParty);
	for (int i = 0; i < nNumOfParty; ++i)
	{
		std::cin >> nTempLength;
		std::vector<int> vTemp{};
		vTemp.reserve(nTempLength);
		for (int j = 0; j < nTempLength; ++j)
		{
			int nTemp{};
			std::cin >> nTemp;
			vTemp.push_back(nTemp);
		}
		vParty.push_back(vTemp);
	}
}
bool isThereTruthPerson_acmicpc1043(std::vector<int>& vParty, const std::vector<bool>& vTruthPerson)
{
	for (int i = 0; i < vParty.size(); i++)
	{
		if (vTruthPerson[vParty[i]])
			return true;
	}
	return false;
}
