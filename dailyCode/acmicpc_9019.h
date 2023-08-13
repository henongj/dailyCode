#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
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
#include <fstream>
#include<functional>

//https://www.acmicpc.net/problem/9019
//DSLR
namespace acmicpc_9019
{
	using namespace std;

	void solution(void);
	void calculate(int& nStart, int nEnd);
	int command_D(int nNum);
	int command_S(int nNum);
	int command_L(int nNum);
	int command_R(int nNum);
	void inputData(int& nStart, int& nEnd);

	void solution(void)
	{
		int nTestCase;

		cin >> nTestCase;

		for (int i = 0; i < nTestCase; i++)
		{
			int nStart{};
			int nEnd{};

			inputData(nStart, nEnd);
			calculate(nStart, nEnd);

		}

	}

	void calculate(int& nStart, int nEnd)
	{
		queue<pair<int, string>> qCommand{};

		string strCommand{};
		qCommand.push({ nStart, strCommand });
		pair<int, string> pFront{};
		vector<int> vVisited(10000, 0);

		while (true)
		{
			pFront = qCommand.front();
			qCommand.pop();

			if (!vVisited[pFront.first])
			{
				vVisited[pFront.first] = 1;
				int nNum = pFront.first;
				strCommand = pFront.second;

				int arrCommand[4]{};

				arrCommand[0] = command_D(nNum);
				arrCommand[1] = command_S(nNum);
				arrCommand[2] = command_L(nNum);
				arrCommand[3] = command_R(nNum);

				for (int i = 0; i < 4; i++)
				{
					if (arrCommand[i] == nEnd)
					{
						strCommand += (i == 0) ? 'D' : (i == 1) ? 'S' : (i == 2) ? 'L' : 'R';
						cout << strCommand << endl;
						return;
					}
					else
					{
						if (!vVisited[arrCommand[i]])
						{
							string strTemp = strCommand;
							strTemp += (i == 0) ? 'D' : (i == 1) ? 'S' : (i == 2) ? 'L' : 'R';
							qCommand.push({ arrCommand[i], strTemp });
						}
					}
				}

			}

		}
	}

	int command_D(int nNum)
	{
		return (nNum * 2) % 10000;
	}

	int command_S(int nNum)
	{
		nNum = (nNum - 1) % 10000;

		if (nNum < 0)
			nNum = 9999;

		return nNum;
	}

	int command_L(int nNum)
	{
		int nD1 = nNum / 1000;
		int nD2 = (nNum % 1000) / 100;
		int nD3 = (nNum % 100) / 10;
		int nD4 = nNum % 10;

		nNum = nD2 * 1000 + nD3 * 100 + nD4 * 10 + nD1;

		return nNum;
	}

	int command_R(int nNum)
	{
		int nD1 = nNum / 1000;
		int nD2 = (nNum % 1000) / 100;
		int nD3 = (nNum % 100) / 10;
		int nD4 = nNum % 10;

		nNum = nD4 * 1000 + nD1 * 100 + nD2 * 10 + nD3;

		return nNum;
	}

	void inputData(int& nStart, int& nEnd)
	{
		cin >> nStart >> nEnd;
	}

}

