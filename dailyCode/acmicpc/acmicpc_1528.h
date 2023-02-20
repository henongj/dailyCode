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
using namespace std;

//https://www.acmicpc.net/problem/1528
//�ݹμ��� ��
void funcGetGMS(void);

void Solution(void)
{
	funcGetGMS();
}



void funcGetGMS(void)
{
	int nNumber{};
	int nSevenQuotient{};
	int nSevenRemainder{};

	int nFourQuotient{};
	int nFourRemainder{};
	int nScaleTable[7]{ 111111,11111,1111,111,111,11,1 };


	cin >> nNumber;

	// 4�� ���� ��, ������
	nFourQuotient = nNumber / 4;
	nFourRemainder = nNumber % 4;

	// 4�� ������ �������� �ʴ� ���, ���� 1�� ���̸鼭 �������� 4�� ���ϰ� 7�� ������ ���������� Ȯ��
	while (nFourQuotient >= 0)
	{
		nSevenQuotient = nFourRemainder / 7;
		nSevenRemainder = nFourRemainder % 7;

		if (nSevenRemainder == 0)
			break;

		nFourQuotient--;
		nFourRemainder += 4;
	}

	// ���� �� ���� ���
	if (nNumber == nFourRemainder - 4)
	{
		cout << -1;
		return;
	}

	// 4�� 7�� ���� ���ϸ�, 4�� 7�θ� �̷���� �ݹμ��� ǥ���Ѵ�
	vector<int> vecGMS{};
	vecGMS.reserve(1000);

	int nTableIndex{};
	nTableIndex = 0;
	while (nFourQuotient != 0 || nSevenQuotient != 0)
	{
		if (nScaleTable[nTableIndex] <= nFourQuotient)
		{
			vecGMS.push_back(nScaleTable[nTableIndex] * 4);
			nFourQuotient -= nScaleTable[nTableIndex];
		}
		if (nScaleTable[nTableIndex] <= nSevenQuotient)
		{
			vecGMS.push_back(nScaleTable[nTableIndex] * 7);
			nSevenQuotient -= nScaleTable[nTableIndex];
		}
		if (nFourQuotient < nScaleTable[nTableIndex] && nSevenQuotient < nScaleTable[nTableIndex])
			nTableIndex++;
	}

	sort(vecGMS.begin(), vecGMS.end());
	int nSize{};
	nSize = vecGMS.size();
	for (int i = 0; i < nSize; i++)
		cout << vecGMS[i] << " ";


}

/*
void funcGetGMS(void)
{
	int nNumber{};
	int nSevenQuotient{};
	int nSevenRemainder{};

	int nFourQuotient{};
	int nFourRemainder{};

	// 7�� ������ ������ ���, �� ���� ��ŭ ���

	cin >> nNumber;

	nSevenQuotient = nNumber / 7;
	nSevenRemainder = nNumber % 7;

	if (nSevenRemainder == 0)
	{
		for (int i = 0; i < nSevenQuotient; i++)
			cout << 7 << " ";
		return;
	}

	// 7�� ������ �������� �ʴ� ���, ���� 1�� ���̸鼭 �������� 7�� ���ϰ� 4�� ������ ���������� Ȯ��
	while (nSevenQuotient >= 0)
	{
		nFourQuotient = nSevenRemainder / 4;
		nFourRemainder = nSevenRemainder % 4;
		if (nFourRemainder == 0)
		{
			for (int i = 0; i < nFourQuotient; i++)
				cout << 4 << " ";
			for (int i = 0; i < nSevenQuotient; i++)
				cout << 7 << " ";
			return;
		}

		nSevenQuotient--;
		nSevenRemainder += 7;
	}

	cout << "-1";

}*/

/*
void funcGetGMS(void)
{
	int nNumber{};
	int nSevenQuotient{};
	int nSevenRemainder{};

	int nFourQuotient{};
	int nFourRemainder{};
	int nScaleTable[7]{ 111111,11111,1111,111,111,11,1 };

	// 7�� ������ ������ ���, �� ���� ��ŭ ���

	cin >> nNumber;

	nSevenQuotient = nNumber / 7;
	nSevenRemainder = nNumber % 7;

	// 7�� ������ �������� �ʴ� ���, ���� 1�� ���̸鼭 �������� 7�� ���ϰ� 4�� ������ ���������� Ȯ��
	while (nSevenQuotient >= 0)
	{
		nFourQuotient = nSevenRemainder / 4;
		nFourRemainder = nSevenRemainder % 4;

		if (nFourRemainder == 0)
			break;

		nSevenQuotient--;
		nSevenRemainder += 7;
	}

	// ���� �� ���� ���
	if (nFourQuotient == 0 && nSevenQuotient == 0)
	{
		cout << -1;
		return;
	}

	// 4�� 7�� ���� ���ϸ�, 4�� 7�θ� �̷���� �ݹμ��� ǥ���Ѵ�
	vector<int> vecGMS{};
	vecGMS.reserve(1000);

	int nTableIndex{};
	nTableIndex = 0;
	while(nFourQuotient != 0 || nSevenQuotient != 0)
	{
		if (nScaleTable[nTableIndex] <= nFourQuotient)
		{
			vecGMS.push_back(nScaleTable[nTableIndex] * 4);
			nFourQuotient -= nScaleTable[nTableIndex];
		}
		if (nScaleTable[nTableIndex] <= nSevenQuotient)
		{
			vecGMS.push_back(nScaleTable[nTableIndex] * 7);
			nSevenQuotient -= nScaleTable[nTableIndex];
		}
		if (nFourQuotient < nScaleTable[nTableIndex] && nSevenQuotient < nScaleTable[nTableIndex])
			nTableIndex++;
	}

	sort(vecGMS.begin(), vecGMS.end());
	int nSize{};
	nSize = vecGMS.size();
	for (int i = 0; i < nSize; i++)
		cout << vecGMS[i] << " ";


}
*/