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

//https://www.acmicpc.net/problem/1676
//팩토리얼 0의 개수
void solution_acmicpc1676(void);
bool isDivisibleBy5(const int nInput, int& nResult);
void countDivisibleBy5(const int nInput, int& nResult);


int mainSpace_acmicpc1676(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution_acmicpc1676();

	return 0;
}

void solution_acmicpc1676(void)
{
	int nFactorial{};
	int nResult{};
	int nResult2{};

	std::cin >> nFactorial;
	nResult = 0;
	nResult2 = 0;

	for (int i = 1; i <= nFactorial; i++)
	{
		int nTemp{};
		int nTemp2{};
		/*if (isDivisibleBy5(i, nTemp))
			nResult += nTemp;*/
		countDivisibleBy5(i, nTemp2);
		nResult2 += nTemp2;
	}

	//std::cout << nResult << std::endl;
	std::cout << nResult2 << std::endl;
}

bool isDivisibleBy5(const int nInput, int& nResult)
{
	if (!(nInput % 5 == 0))
		return false;

	int nDividend = nInput;
	nResult = 0;

	while (nDividend % 5 == 0)
	{
		nDividend /= 5;
		nResult++;
	}

	return true;
}

void countDivisibleBy5(const int nInput, int& nResult)
{
	nResult = 0;
	int nDividend = nInput;

	while (nDividend % 5 == 0)
	{
		nDividend /= 5;
		nResult++;
	}
}
