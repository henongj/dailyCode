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
void swapData_acmicpc1083(std::vector<int>& vData, int& nIndexStart, int& nIndexDestination);
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

/*
5
1 2 3 4 99
4

* */
void swapData_acmicpc1083(std::vector<int>& vData, int& nIndexStart, int& nIndexDestination)
{
	int nTemp = vData[nIndexStart];

	vData[nIndexStart] = vData[nIndexDestination];
	int nIndex = nIndexDestination;

	// 4 3 2 
	while (nIndex > nIndexStart)
	{
		vData[nIndex] = vData[nIndex - 1];
		nIndex--;
	}
	vData[nIndex + 1] = nTemp;
}

void solution_acmicpc1083(void)
{
	int nN{};
	std::vector<int> vData{};
	int nS{};
	int nSwapCount{};

	int nIndex{};
	int nIndexMax{};
	int nDistance{};

	dataInput_acmicpc1083(nN, vData, nS);

	nSwapCount = nS;
	nIndex = 0;
	while (0 < nSwapCount && nIndex < nN)
	{
		nIndexMax = nIndex;
		for (int iter = nIndex + 1;
			iter < nN && iter - nIndex <= nSwapCount;
			iter++)
		{
			if (vData[nIndexMax] < vData[iter])
				nIndexMax = iter;
		}

		if (vData[nIndex] < vData[nIndexMax])
		{
			swapData_acmicpc1083(vData, nIndex, nIndexMax);
			nSwapCount -= (nIndexMax - nIndex);
		}

		////print vData
		//for (int i = 0; i < nN; i++)
		//	printf("%d, ", vData[i]);
		//printf("\n");

		nIndex++;
	}
	for (int i = 0; i < nN; i++)
		std::cout << vData[i] << " ";
}
