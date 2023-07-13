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

//https://www.acmicpc.net/problem/1117
//»öÄ¥ 1
void solution_acmicpc1117(void);
void dataInput_acmicpc1117(int& nWidth, int& nHeight, int& nFoldXpos, int& nFoldYTimes, std::pair<int, int>& pairPosition1, std::pair<int, int>& pairPosition2);

int mainSpace01_acmicpc1117(void)
{
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	solution_acmicpc1117();

	return 0;
}

void solution_acmicpc1117(void)
{
	int nWidth{};
	int nHeight{};
	int nFoldXpos{};
	int nFoldYTimes{};
	std::pair<int, int> pairPos1{};
	std::pair<int, int> pairPos2{};
	long long nNotPainted{};

	dataInput_acmicpc1117(nWidth, nHeight, nFoldXpos, nFoldYTimes, pairPos1, pairPos2);
	nNotPainted = (long long)nWidth * (long long)nHeight;

	std::pair<int, int> pairPosLeftBottom = { pairPos1.first + nFoldXpos, pairPos1.second };
	std::pair<int, int> pairPosRightTop = { pairPos2.first + nFoldXpos, pairPos2.second };

	long long nPainted{};
	long long nNumOfFold = nFoldYTimes + 1;
	long long nSquareHeight = pairPosRightTop.second - pairPosLeftBottom.second;
	long long nPaintedDown = 0;
	long long nPaintedUp = pairPos2.first - pairPos1.first;

	for (int i = pairPosLeftBottom.first; i < pairPosRightTop.first; i++)
	{
		if (i < nFoldXpos * 2 && i < nWidth)
			nPaintedDown++;
	}
	nPainted = (nPaintedUp + nPaintedDown) * nNumOfFold * nSquareHeight;

	nNotPainted -= nPainted;
	std::cout << nNotPainted << "\n";
}

void dataInput_acmicpc1117(int& nWidth, int& nHeight, int& nFoldXpos, int& nFoldYTimes, std::pair<int, int>& pairPosition1, std::pair<int, int>& pairPosition2)
{
	std::cin >> nWidth;
	std::cin >> nHeight;
	std::cin >> nFoldXpos;
	std::cin >> nFoldYTimes;
	std::cin >> pairPosition1.first >> pairPosition1.second;
	std::cin >> pairPosition2.first >> pairPosition2.second;
}
