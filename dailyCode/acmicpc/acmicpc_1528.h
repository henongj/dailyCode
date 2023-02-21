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

int main(void)
{
	funcGetGMS();

	return 0;
}

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

}