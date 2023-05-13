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

/*
https://www.acmicpc.net/problem/1025
������ ã��

1 �� N, M �� 9
N�� M���� 9�� 9999�� 9999������ ������ ���� �� �ִ�. (int)

1. ���ڸ� ���� ���
2. �� ���ڵ��� �̾�ٿ��� ���� �� �ִ� ���� ���������� �Ǻ��ϴ� ���

�帧:
���� nRow, �ప nColumn, �������� nRowAdd, �������� nColumnAdd

1. nRow, nColumn, nRowAdd, nColumnAdd�� 0���� �ʱ�ȭ

�迭 ������ ����� ��
 nRow�� nRowAdd�� ���� ����, nColumnAdd�� nColumnAdd�� ���� �����Ѵ�.
 while�� ���������� nRow nColumn ���� �ٲ۴�.
�ݵ�� ��� ��츦 Ž��, ���� ū ���� ������ ��ȯ
*/


int getPerfectSqureNumberIn2DVector(std::vector<std::vector<int>>& vvData, std::unordered_map<int, int>& mapPerfectSqureNumber);
void dataInput_acmicpc1025(std::vector<std::vector<int>>& vvData, int& nN, int& nM);
void makePerfectSqureNumberTable(std::unordered_map<int, int>& mapPerfectSqureNumber, int nMaximumValue);
int main(void)
{
	int nN{};
	int nM{};
	int nMaximumKey{};
	std::vector<std::vector<int>> vvData{};
	std::unordered_map<int, int> mapPerfectSqureNumber{};
	nMaximumKey = 999999999;

	dataInput_acmicpc1025(vvData, nN, nM);
	makePerfectSqureNumberTable(mapPerfectSqureNumber, nMaximumKey);

	std::cout << getPerfectSqureNumberIn2DVector(vvData, mapPerfectSqureNumber);


	return 0;
}

int getPerfectSqureNumberIn2DVector(std::vector<std::vector<int>>& vvData, std::unordered_map<int, int>& mapPerfectSqureNumber)
{
	size_t nRowSize{};
	size_t nColumnSize{};
	int nMaximumPerfectSqureNumber{};

	nRowSize = vvData.size();
	nColumnSize = vvData[0].size();
	nMaximumPerfectSqureNumber = -1;

	int nRowStart{};
	int nColumnStart{};
	int nRowIndexAdder{};
	int nColumnIndexAdder{};
	int nKey{};

	for (nRowStart = 0; nRowStart < nRowSize; nRowStart++)
	{
		for (nColumnStart = 0; nColumnStart < nColumnSize; nColumnStart++)
		{
			printf("--------nRowStart : %d, nColumnStart : %d-----------\n", nRowStart, nColumnStart);
			int nRowIndex{};
			int nColumnIndex{};
			int nData{};

			nData = 0;
			nRowIndex = nRowStart;
			nColumnIndex = nColumnStart;
			nRowIndexAdder = 0;
			nColumnIndexAdder = 1;

			for (nRowIndexAdder; nRowIndexAdder < nRowSize; nRowIndexAdder++)
			{
				for (nColumnIndexAdder; nColumnIndexAdder < nColumnSize; nColumnIndexAdder++)
				{
					while (0 <= nRowIndex && nRowIndex < nRowSize && 0 <= nColumnIndex && nColumnIndex < nColumnSize)
					{
						nData = nData * 10 + vvData[nRowIndex][nColumnIndex];
						printf("nData : %d\n", nData);
						if (mapPerfectSqureNumber.find(nData) != mapPerfectSqureNumber.end())
							nMaximumPerfectSqureNumber = std::max(nMaximumPerfectSqureNumber, mapPerfectSqureNumber[nData]);

						nRowIndex += nRowIndexAdder;
						nColumnIndex += nColumnIndexAdder;
					}

					nRowIndex = nRowStart;
					nColumnIndex = nColumnStart;
					nData = 0;
				}
			}

		}
	}


	return nMaximumPerfectSqureNumber;
}


void dataInput_acmicpc1025(std::vector<std::vector<int>>& vvData, int& nN, int& nM)
{
	std::string strInputData{};
	int nRemainder{};
	int nQuotient{};

	std::cin >> nN >> nM;

	vvData.reserve(nN);
	for (int i = 0; i < nN; i++)
	{
		vvData.push_back(std::vector<int>{});
		vvData[i].reserve(nM);
	}
	strInputData.reserve(nM);

	for (int row = 0; row < nN; row++)
	{
		std::cin >> strInputData;

		for (int col = 0; col < nM; col++)
			vvData[row].push_back(((int)strInputData[col] - (int)'0'));
	}


	//print vvData
	for (int i = 0; i < nN; i++)
	{
		for (int j = 0; j < nM; j++)
		{
			printf("%d, ", vvData[i][j]);
		}
		printf("\n");
	}

}

void makePerfectSqureNumberTable(std::unordered_map<int, int>& mapPerfectSqureNumber, int nMaximumKey)
{
	int nValue{};
	int nKey{};

	nValue = 0;
	nKey = 0;

	while (nKey < nMaximumKey)
	{
		mapPerfectSqureNumber[nKey] = nValue;

		nValue++;
		nKey = nValue * nValue;
	}

	/*
	for (auto nVal : mapPerfectSqureNumber)
	{
		printf("%d %d\n", nVal.first, nVal.second);
	}
	*/
}
