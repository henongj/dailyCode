#pragma once
#include<algorithm>
#include<iostream>
#include<map>
#include<utility>
#include<vector>

namespace acmicpc1229{
	//https://www.acmicpc.net/problem/1229
	//À°°¢¼ö
	void solution_acmicpc1229(void);
	void writeMemo(std::vector<int>& vHexagonTable, const int& nRangeAnswer, int* arrMemo, int nNumber);
	void inputData_acmicpc1229(int& nNumber);
	void generateHexagonNumber(std::vector<int>& vHexagonTable, int nRange);


	int main(void)
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		solution_acmicpc1229();

		return 0;
	}

	void solution_acmicpc1229(void)
	{
		int nNumber{};
		const int nRangeHexagonNumber = 1000000;
		const int nRangeAnswer = 1000000;
		std::vector<int> vHexagonTable{};
		int* arrMemo{};
		arrMemo = new int[nRangeAnswer + 1] {};

		inputData_acmicpc1229(nNumber);

		generateHexagonNumber(vHexagonTable, nRangeHexagonNumber);

		writeMemo(vHexagonTable, nRangeAnswer, arrMemo, nNumber);

		std::cout << arrMemo[nNumber] << "\n";

		delete[] arrMemo;
	}

	void writeMemo(std::vector<int>& vHexagonTable, const int& nRangeAnswer, int* arrMemo, int nNumber)
	{
		for (int i = 0; i < vHexagonTable.size(); i++)
		{
			int nTemp = vHexagonTable[i];
			int nCount = 1;
			while (nTemp <= nRangeAnswer)
			{
				arrMemo[nTemp] = nCount;
				nCount++;
				nTemp += vHexagonTable[i];
			}
		}

		for (int i = 1; i <= nNumber; i++)
		{
			int nIndex = i;
			int nTemp = i;
			int nCount = 0;

			for (size_t nPick = vHexagonTable.size() - 1; nPick > 0; nPick--)
			{
				if (nIndex - vHexagonTable[nPick] > 0)
				{
					arrMemo[nIndex] = std::min(arrMemo[nIndex], arrMemo[nIndex - vHexagonTable[nPick]] + 1);
				}
			}

		}
	}

	void inputData_acmicpc1229(int& nNumber)
	{
		std::cin >> nNumber;
	}

	void generateHexagonNumber(std::vector<int>& vHexagonTable, int nRange)
	{
		vHexagonTable.reserve(nRange);

		int nHexagonNumber{};
		int nHexagonNumberPrev{};

		nHexagonNumber = 1;
		nHexagonNumberPrev = 0;
		for (int i = 1; true; i++)
		{
			nHexagonNumber = nHexagonNumberPrev + (i * 4) - 3;
			vHexagonTable.push_back(nHexagonNumber);

			nHexagonNumberPrev = nHexagonNumber;
			if (nHexagonNumber > nRange)
				break;
		}
	}
}
