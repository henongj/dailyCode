#pragma once
#include<iostream>
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

namespace acmicpc1188_wrongAnswer
{
	//https://www.acmicpc.net/problem/1188
	//음식 평론가
	void solution_acmicpc1188(void);
	void inputData_acmicpc1188(int& nPeopleNum, int& nSausageNum);
	bool isCoprime(int nNumber1, int nNumber2);
	int mainSpace01(void)
	{

		solution_acmicpc1188();

		return 0;
	}

	void solution_acmicpc1188(void)
	{
		int nPeopleNum{};
		int nSausageNum{};
		int nResult{};

		inputData_acmicpc1188(nPeopleNum, nSausageNum);

		int nSausageRemain = nSausageNum % nPeopleNum;

		if (!(nSausageNum % nPeopleNum))
			nResult = 0;
		else if (isCoprime(nPeopleNum, nSausageRemain))
			nResult = nPeopleNum - 1;
		else
		{
			int nCuttingTimes{};
			nCuttingTimes = 1;
			while (nSausageRemain * nCuttingTimes < nPeopleNum)
				nCuttingTimes++;
			nResult = (nCuttingTimes - 1) * nSausageNum;
		}

		std::cout << nResult;
	}

	void inputData_acmicpc1188(int& nPeopleNum, int& nSausageNum)
	{
		std::cin >> nSausageNum;
		std::cin >> nPeopleNum;
	}

	bool isCoprime(int nNumber1, int nNumber2)
	{
		int nStart = 2;

		while (nStart * nStart <= nNumber1 || nStart * nStart <= nNumber2)
		{
			if (!(nNumber1 % nStart) && !(nNumber2 % nStart))
				return false;
			nStart++;
		}
		return true;
	}

}
