#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
//https://www.acmicpc.net/problem/10816
//숫자 카드 2

void binarySearchUpperBound(const std::vector<int>& vCards, const int nTarget, int& nResult);
void binarySearchLowerBound(const std::vector<int>& vCards, const int nTarget, int& nResult);
void acmicpc_10816_dataInput(int& nNumOfCards, std::vector<int>& vecCards, int& nNumOfTargets, std::vector<int>& targets);

void acmicpc_10816_4(void)
{
	int nNumOfCards{};
	std::vector<int> vecCards{};
	int nNumOfTargets{};
	std::vector<int> vecTargets{};

	acmicpc_10816_dataInput(nNumOfCards, vecCards, nNumOfTargets, vecTargets);

	std::sort(vecCards.begin(), vecCards.end());

	for (int i = 0; i < nNumOfTargets; i++)
	{
		int nTarget = vecTargets[i];
		int nUpperBound{};
		int nLowerBound{};
		binarySearchUpperBound(vecCards, nTarget, nUpperBound);
		binarySearchLowerBound(vecCards, nTarget, nLowerBound);
		std::cout << nUpperBound - nLowerBound << " ";
	}

}

void binarySearchLowerBound(const std::vector<int>& vCards, const int nTarget, int& nResult)
{
	int nLeft{};
	int nRight{};
	int nMid{};

	nLeft = 0;
	nRight = vCards.size() - 1;

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (vCards[nMid] < nTarget)
			nLeft = nMid + 1;
		else
			nRight = nMid - 1;
	}

	nResult = nLeft;
}
void acmicpc_10816_dataInput(int& nNumOfCards, std::vector<int>& vecCards, int& nNumOfTargets, std::vector<int>& targets)
{
	int nInput{};
	std::cin >> nNumOfCards;
	for (int i = 0; i < nNumOfCards; i++)
	{
		std::cin >> nInput;
		vecCards.push_back(nInput);
	}

	std::cin >> nNumOfTargets;
	for (int i = 0; i < nNumOfTargets; i++)
	{
		std::cin >> nInput;
		targets.push_back(nInput);
	}
}
void binarySearchUpperBound(const std::vector<int>& vCards, const int nTarget, int& nResult)
{
	int nLeft{};
	int nRight{};
	int nMid{};

	nLeft = 0;
	nRight = vCards.size() - 1;

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (vCards[nMid] <= nTarget)
			nLeft = nMid + 1;
		else
			nRight = nMid - 1;
	}

	nResult = nLeft;
}
/*
//Time limite exceeded
void acmicpc_10816(void)
{
	int nNumOfCards{};
	std::vector<int> vecCards{};
	int nInput{};
	int nNumOfTargets{};
	std::vector<int> vecTargets{};

	std::cin >> nNumOfCards;
	for (int i = 0; i < nNumOfCards; i++)
	{
		std::cin >> nInput;
		vecCards.push_back(nInput);
	}

	std::cin >> nNumOfTargets;
	for (int i = 0; i < nNumOfTargets; i++)
	{
		std::cin >> nInput;
		vecTargets.push_back(nInput);
	}

	std::sort(vecCards.begin(), vecCards.end());

	for (int i = 0; i < nNumOfTargets; i++)
	{
		int nCount{};
		int nTarget = vecTargets[i];
		int nLeft = 0;
		int nRight = nNumOfCards - 1;
		int nMid = (nLeft + nRight) / 2;

		while (nLeft <= nRight)
		{
			if (vecCards[nMid] == nTarget)
			{
				nCount++;
				int nTemp = nMid;
				while (nTemp > 0 && vecCards[nTemp - 1] == nTarget)
				{
					nCount++;
					nTemp--;
				}
				nTemp = nMid;
				while (nTemp < nNumOfCards - 1 && vecCards[nTemp + 1] == nTarget)
				{
					nCount++;
					nTemp++;
				}
				break;
			}
			else if (vecCards[nMid] < nTarget)
			{
				nLeft = nMid + 1;
			}
			else
			{
				nRight = nMid - 1;
			}
			nMid = (nLeft + nRight) / 2;
		}
		std::cout << nCount << " ";
	}
}
 // Time limite exceeded
void acmicpc_10816(void)
{
	int nNumOfCards{};
	std::map<int, int> mapCardCounts{};
	int nInput{};
	int nNumOfTargets{};

	std::cin >> nNumOfCards;
	for (int i = 0; i < nNumOfCards; i++)
	{
		std::cin >> nInput;
		mapCardCounts[nInput]++;
	}

	std::cin >> nNumOfTargets;
	for (int i = 0; i < nNumOfTargets; i++)
	{
		std::cin >> nInput;
		std::cout << mapCardCounts[nInput] << " ";
	}
}
void acmicpc_10816(void)
{
	int nNumOfCards{};
	std::unordered_map<int, int> mapCardCounts{};
	int nInput{};
	int nNumOfTargets{};

	std::cin >> nNumOfCards;
	for (int i = 0; i < nNumOfCards; i++)
	{
		std::cin >> nInput;
		mapCardCounts[nInput]++;
	}

	std::cin >> nNumOfTargets;
	for (int i = 0; i < nNumOfTargets; i++)
	{
		std::cin >> nInput;
		std::cout << mapCardCounts[nInput] << " ";
	}
}
*/
