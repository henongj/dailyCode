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

namespace acmicpc1188
{
	//https://www.acmicpc.net/problem/1188
	//음식 평론가
	void solution_acmicpc1188(void);
	int GCD(int a, int b);

	int mainSpace(void)
	{
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc1188();

		return 0;
	}

	int GCD(int a, int b) {
		if (a % b == 0)
			return b;

		return GCD(b, a % b);
	}
	void solution_acmicpc1188(void)
	{
		int nPeopleNum{};
		int nSausageNum{};
		int nGCD{};
		int nResult{};

		std::cin >> nSausageNum;
		std::cin >> nPeopleNum;


		nGCD = GCD(nPeopleNum, nSausageNum);
		nResult = nPeopleNum - nGCD;
		std::cout << nResult;

	}
}
