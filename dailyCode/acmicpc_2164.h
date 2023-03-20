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


//https://www.acmicpc.net/problem/2164
//카드2
void cardProblem(void)
{
	/*
	버리기 = start index ++
	맨뒤로 = pushback(v[startIndex]) startIndex ++, end++
	start == end 일때 v[startIndex] 반환
	*/
	std::vector<int> vCards{};
	int nNumOfCards{};
	int nStartIndex{};
	int nEndIndex{};

	std::cin >> nNumOfCards;
	unsigned long long szVectorCapacity{};
	szVectorCapacity = (unsigned long long)nNumOfCards * 2;
	vCards.reserve(szVectorCapacity);
	
	for (int i = 1; i <= nNumOfCards; ++i)
		vCards.push_back(i);

	nEndIndex = nNumOfCards - 1;

	while (nStartIndex != nEndIndex)
	{
		if (nStartIndex != nEndIndex)
			++nStartIndex;
		if (nStartIndex != nEndIndex)
		{
			vCards.push_back(vCards[nStartIndex]);
			++nStartIndex;
			++nEndIndex;
		}
	}

	printf("%d", vCards[nStartIndex]);

}