#pragma once

#include<iostream>
#include<queue>

//https://www.acmicpc.net/problem/11866
//요세푸스 문제 0
void acmicpc_11866(void)
{
	std::queue<int> qPerson{};
	int nNumOfPerson{};
	int nNumOfKill{};
	int nCount{};
	std::cin >> nNumOfPerson >> nNumOfKill;

	for (int i = 1; i <= nNumOfPerson; i++)
		qPerson.push(i);

	std::cout << "<";
	int nFront{};
	nCount = 0;
	while (!qPerson.empty())
	{
		nFront = qPerson.front();
		qPerson.pop();
		nCount++;

		if (nCount == nNumOfKill)
		{
			std::cout << nFront;
			if (qPerson.size() > 0)
				std::cout << ", ";
			nCount = 0;
		}
		else
			qPerson.push(nFront);
	}

	std::cout << ">" << std::endl;
}