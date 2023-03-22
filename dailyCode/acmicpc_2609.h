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


//https://www.acmicpc.net/problem/2609
//최대공약수와 최소공배수

void acmicpc_2609(void)
{
	int nNumber1{};
	int nNumber2{};

	std::cin >> nNumber1 >> nNumber2;

	int nTemp{};
	int nGCD{};
	int nLCM{};

	if (nNumber2 < nNumber1)
	{
		nTemp = nNumber1;
		nNumber1 = nNumber2;
		nNumber2 = nTemp;
	}

	nTemp = nNumber1;
	while (nTemp > 0)
	{
		if (nNumber1 % nTemp == 0 && nNumber2 % nTemp == 0)
		{
			nGCD = nTemp;
			break;
		}
		nTemp--;
	}

	nTemp = nNumber2;
	while (nTemp <= nNumber1 * nNumber2)
	{
		if (nTemp % nNumber1 == 0 && nTemp % nNumber2 == 0)
		{
			nLCM = nTemp;
			break;
		}
		nTemp++;
	}

	std::cout << nGCD << std::endl;
	std::cout << nLCM << std::endl;
}
