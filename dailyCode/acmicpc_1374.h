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

//https://www.acmicpc.net/problem/1374
//°­ÀÇ½Ç
void solution_acmicpc1374(void);
void dataInput_acmicpc1374(int& nLecture, std::vector<std::pair<int, int>>& vLecture);

int mainSpace01_acmicpc1374(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	solution_acmicpc1374();

	return 0;
}

void solution_acmicpc1374(void)
{
	int nLecture;
	std::vector<std::pair<int, int>> vLecture;
	dataInput_acmicpc1374(nLecture, vLecture);

	std::sort(vLecture.begin(), vLecture.end());

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(vLecture[0].second);

	for (int i = 1; i < nLecture; ++i)
	{
		if (pq.top() <= vLecture[i].first)
			pq.pop();
		pq.push(vLecture[i].second);
	}

	std::cout << pq.size() << std::endl;
}

void dataInput_acmicpc1374(int& nLecture, std::vector<std::pair<int, int>>& vLecture)
{
	std::cin >> nLecture;
	for (int i = 0; i < nLecture; i++)
	{
		int nLectureNum{};
		int nStart{};
		int nEnd{};
		std::cin >> nLectureNum >> nStart >> nEnd;
		vLecture.push_back(std::make_pair(nStart, nEnd));
	}
}

