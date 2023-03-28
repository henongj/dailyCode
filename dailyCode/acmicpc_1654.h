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

//https://www.acmicpc.net/problem/1654
//���� �ڸ���
void getNumOfCuttedLANLine(const std::vector<int>& vLengthOfLAN, int nCuttingLength, long long* nResult);
void acmicpc_1654(void);
void acmicpc_1654(void)
{
	int nNumOfHavingLAN{};
	int nNumOfNeed{};
	std::vector<int> vLengthOfLAN{};
	int nMaximumLength{};
	int nResult{};

	std::cin >> nNumOfHavingLAN;
	std::cin >> nNumOfNeed;
	vLengthOfLAN.reserve(nNumOfNeed);

	for (int i = 0; i < nNumOfHavingLAN; i++)
	{
		int nLength{};
		std::cin >> nLength;
		vLengthOfLAN.push_back(nLength);
		nMaximumLength = std::max(nMaximumLength, nLength);
	}

	//binary search
	long long nStart{};
	long long nEnd{};
	long long nMid{};

	nStart = 1;
	nEnd = nMaximumLength;
	while (nStart <= nEnd)
	{
		nMid = ((nStart + nEnd) / 2);
		long long nNumOfCuttedLANLine{};
		getNumOfCuttedLANLine(vLengthOfLAN, nMid, &nNumOfCuttedLANLine);

		// 1. �ʿ��� �� ���� ���ų� ������ �� ��� �߶�� �Ѵ�
		if (nNumOfCuttedLANLine >= nNumOfNeed)
		{
			nStart = nMid + 1;
			// 1.1. �̰� ������ ���� ������ �ִ� ���̸� �����Ѵ�
			nResult = nMid;
		}
		else // 2. �ʿ��� �� ���� ������ �� ª�� �߶�� �Ѵ�
			nEnd = nMid - 1;
	}
	std::cout << nResult << std::endl;

}
void getNumOfCuttedLANLine(const std::vector<int>& vLengthOfLAN, int nCuttingLength, long long* nResult)
{
	long long nNumOfCuttedLANLine{};
	size_t szSize{};
	szSize = vLengthOfLAN.size();
	for (size_t i = 0; i < szSize; i++)
		nNumOfCuttedLANLine += vLengthOfLAN[i] / nCuttingLength;

	*nResult = nNumOfCuttedLANLine;
}


