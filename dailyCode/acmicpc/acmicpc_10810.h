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


void acmicpcProblem10810(void);
void inputBallInBucket(std::vector<int>* vBucket, int nStart, int nEnd, int nColorNumber);


void acmicpcProblem10810(void)
{
	int nBucket{};
	int nNumOfBall{};
	std::vector<int> vBucket{};

	int nStart{};
	int nEnd{};
	int nColorNumber{};

	std::cin >> nBucket >> nNumOfBall;
	vBucket.resize(nBucket + 1);

	for (int i = 0; i < nNumOfBall; i++)
	{
		cin >> nStart >> nEnd >> nColorNumber;
		inputBallInBucket(&vBucket, nStart, nEnd, nColorNumber);
	}

	for (int i = 1; i <= nBucket; i++)
		printf("%d ", vBucket[i]);
}

void inputBallInBucket(std::vector<int>* vBucket, int nStart, int nEnd, int nColorNumber)
{
	for (int i = nStart; i <= nEnd; i++)
		(*vBucket)[i] = nColorNumber;
}
