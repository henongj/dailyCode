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


//https://www.acmicpc.net/problem/1083
//1083 ¼ÒÆ®
void dataInput_acmicpc1083(int& nN, std::vector<int>& vData, int& nS);
void swapData_acmicpc1083(int& nNumber1, int& nNumber2);
void solution_acmicpc1083(void);

int run_acmicpc1083(void)
{
	solution_acmicpc1083();
	return 0;
}

void dataInput_acmicpc1083(int& nN, std::vector<int>& vData, int& nS)
{
	std::cin >> nN;
	vData.resize(nN);

	for (int i = 0; i < nN; i++)
		std::cin >> vData[i];

	std::cin >> nS;
}

void swapData_acmicpc1083(int& nNumber1, int& nNumber2)
{
	int nTemp = nNumber1;
	nNumber1 = nNumber2;
	nNumber2 = nTemp;
}

void solution_acmicpc1083(void)
{
	int nN{};
	std::vector<int> vData{};
	int nS{};
	int nSwapCount{};
	int nIndex{};

	dataInput_acmicpc1083(nN, vData, nS);

	nSwapCount = 0;
	nIndex = 0;
	while (nSwapCount < nS && nIndex < nN - 1)
	{
		if (vData[nIndex] < vData[nIndex + 1])
		{
			swapData_acmicpc1083(vData[nIndex], vData[nIndex + 1]);
			nSwapCount++;
			nIndex = 0;
		}

		nIndex++;
	}

	for (int i = 0; i < nN; i++)
		std::cout << vData[i] << " ";

}
