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

//https://www.acmicpc.net/problem/11723
//С§Че
void solution_acmicpc11723(void);
void addData(int* nArr, int nDataAdd);
void removeData(int* nArr, int nDataRemove);
void checkData(int* nArr, int nDataCheck);
void toggleData(int* nArr, int nDataToggle);
void fillArr(int* nArr, int nLength);
void emptyArr(int* nArr, int nLength);

int mainSpace01_acmicpc11723(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	solution_acmicpc11723();

	return 0;
}

void solution_acmicpc11723(void)
{

	int nNumOfCommand{};
	std::cin >> nNumOfCommand;

	int nArr[21]{};
	std::string strCommand{};
	int nData{};

	void(*pFunc[256])(int*, int) {};

	//function pointer
	pFunc['c'] = checkData;
	pFunc['r'] = removeData;
	pFunc['t'] = toggleData;
	pFunc['l'] = fillArr;
	pFunc['a'] = addData;

	pFunc['e'] = emptyArr;

	for (int i = 0; i < nNumOfCommand; i++)
	{
		std::cin >> strCommand;

		if (strCommand[1] == 'l')
			pFunc['l'](nArr, 21);
		else if (strCommand[0] == 'e')
			pFunc['e'](nArr, 21);
		else
		{
			std::cin >> nData;
			pFunc[strCommand[0]](nArr, nData);
		}
	}

}

void addData(int* nArr, int nDataAdd)
{
	nArr[nDataAdd] = 1;
}

void removeData(int* nArr, int nDataRemove)
{
	nArr[nDataRemove] = 0;
}

void checkData(int* nArr, int nDataCheck)
{
	std::cout << nArr[nDataCheck] << "\n";
}

void toggleData(int* nArr, int nDataToggle)
{
	if (nArr[nDataToggle])
		nArr[nDataToggle] = 0;
	else
		nArr[nDataToggle] = 1;
}

void fillArr(int* nArr, int nLength)
{
	for (int i = 0; i < nLength; i++)
		nArr[i] = 1;
}

void emptyArr(int* nArr, int nLength)
{
	for (int i = 0; i < nLength; i++)
		nArr[i] = 0;
}

