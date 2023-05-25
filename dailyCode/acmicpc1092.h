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

//https://www.acmicpc.net/problem/1092
//น่
int solution_acmicpc1092(void);
void dataInput_acmicpc1092(int& nN, std::vector<int>& vCrane, int& nM, std::priority_queue<int>& pqBoxWeight);
int runSpace_acmicpc1092(void)
{
	int n = solution_acmicpc1092();

	printf("%d\n", n);
	return 0;
}

int solution_acmicpc1092(void)
{
	int nN{};
	std::vector<int> vCraneWeight{};
	int nM{};
	std::priority_queue<int> pqBoxWeight{};
	int nTime{};
	std::queue<int> qBoxDelayed{};

	dataInput_acmicpc1092(nN, vCraneWeight, nM, pqBoxWeight);

	std::sort(vCraneWeight.begin(), vCraneWeight.end(), std::greater<int>());

	if (pqBoxWeight.top() > vCraneWeight[0])
		return -1;

	nTime = 0;
	while (!pqBoxWeight.empty())
	{
		int nCraneIndex = 0;
		while (nCraneIndex < nN && 0 < pqBoxWeight.size())
		{
			int nBoxWeight = pqBoxWeight.top();
			pqBoxWeight.pop();

			if (nBoxWeight <= vCraneWeight[nCraneIndex])
				nCraneIndex++;
			else
				qBoxDelayed.push(nBoxWeight);
		}

		while (!qBoxDelayed.empty())
		{
			pqBoxWeight.push(qBoxDelayed.front());
			qBoxDelayed.pop();
		}

		nTime++;
	}

	return nTime;
}

void dataInput_acmicpc1092(int& nN, std::vector<int>& vCrane, int& nM, std::priority_queue<int>& pqBoxWeight)
{
	std::cin >> nN;
	vCrane.resize(nN);
	for (int i = 0; i < nN; i++)
		std::cin >> vCrane[i];

	std::cin >> nM;
	for (int i = 0; i < nM; i++)
	{
		int nTemp{};
		std::cin >> nTemp;
		pqBoxWeight.push(nTemp);
	}
}
