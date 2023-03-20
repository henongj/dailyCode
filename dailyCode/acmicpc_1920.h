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

//https://www.acmicpc.net/problem/1920
//¼ö Ã£±â

void binarySearch(std::vector<int>& vArr, int arrSize, int target, bool* result);
void findNumber(void);


void findNumber(void)
{
	int nN{};
	int nInputData{};
	std::vector<int> vNumbers{};
	vNumbers.reserve(100001);
	int nM{};
	bool bSearchResult{};

	scanf_s("%d", &nN);

	for (int i = 0; i < nN; ++i)
	{
		scanf_s("%d", &nInputData);
		vNumbers.push_back(nInputData);
	}

	std::sort(vNumbers.begin(), vNumbers.end());

	scanf_s("%d", &nM);

	for (int i = 0; i < nM; ++i)
	{
		scanf_s("%d", &nInputData);
		bSearchResult = false;
		binarySearch(vNumbers, nN, nInputData, &bSearchResult);
		if (bSearchResult)
			printf("1\n");
		else
			printf("0\n");
	}
}
/*
void findNumber(void)
{
	int nN{};
	int nInputData{};
	std::vector<int> vNumbers{};
	vNumbers.reserve(100001);
	int nM{};

	scanf("%d", &nN);
	for (int i = 0; i < nN; i++)
	{
		scanf("%d", &nInputData);
		vNumbers.push_back(nInputData);
	}

	std::sort(vNumbers.begin(), vNumbers.end());

	scanf("%d", &nM);

	for (int i = 0; i < nM; i++)
	{
		scanf("%d", &nInputData);
		if (std::binary_search(vNumbers.begin(), vNumbers.end(), nInputData))
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}
*/
/*
void findNumber(void)
{
	int nN{};
	int nInputData{};
	std::unordered_map<int, int> mapNumbers{};
	int nM{};

	scanf("%d", &nN);

	for (int i = 0; i < nN; i++)
	{
		scanf("%d", &nInputData);
		mapNumbers[nInputData] = nInputData;
	}
	scanf("%d", &nM);
	for (int i = 0; i < nM; i++)
	{
		scanf("%d", &nInputData);
		if (mapNumbers.count(nInputData))
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}
*/


void binarySearch(std::vector<int>& vArr, int arrSize, int target, bool* result)
{
	int nStart = 0;
	int nEnd = arrSize - 1;
	int nMid = 0;
	while (nStart <= nEnd)
	{
		nMid = (nStart + nEnd) / 2;
		if (vArr[nMid] == target)
		{
			*result = true;
			return;
		}
		else if (vArr[nMid] > target)
			nEnd = nMid - 1;
		else
			nStart = nMid + 1;
	}
	*result = false;
	return;
}

