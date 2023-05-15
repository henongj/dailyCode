#pragma once
#include<vector>
#include<algorithm>
//https://www.acmicpc.net/problem/10811

void swapInt(int& nNumber1, int& nNumber2)
{
	int nTemp{};
	nTemp = nNumber1;
	nNumber1 = nNumber2;
	nNumber2 = nTemp;
}

void reverseVector(std::vector<int>& vVector, int nStart, int nEnd)
{
	if (nStart > nEnd)
		swapInt(nStart, nEnd);

	while (nStart < nEnd)
	{
		swapInt(vVector[nStart], vVector[nEnd]);
		nStart++;
		nEnd--;
	}
}

void acmicpc10811(void)
{
	int nNumOfBucket{};
	int nNumOfExchange{};

	int nStart{};
	int nEnd{};
	int nValue{};
	std::vector<int> vBucket{};

	std::cin >> nNumOfBucket >> nNumOfExchange;
	nValue = 1;

	vBucket.reserve(nNumOfBucket + 1);
	vBucket.resize(nNumOfBucket + 1);
	for (int i = 1; i <= nNumOfBucket; i++)
	{
		vBucket[nValue] = nValue;
		nValue++;
	}

	for (int i = 0; i < nNumOfExchange; i++)
	{
		std::cin >> nStart >> nEnd;
		reverseVector(vBucket, nStart, nEnd);
	}

	for (int i = 1; i < vBucket.size(); i++)
		std::cout << vBucket[i] << " ";

}#pragma once
