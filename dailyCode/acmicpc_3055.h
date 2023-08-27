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
#include <fstream>
#include<functional>


//https://www.acmicpc.net/problem/3055
//≈ª√‚
namespace acmicpc_3055
{
	using namespace std;

	void solution(void);
	void inputData(int& nRow, int& nColumn, vector<vector<char>>& vvMap, queue<pair<int, int>>& qHedgehog, queue<pair<int, int>>& qWater);
	void BFS(vector<vector<char>>& vvMap, queue<pair<int, int>>& qHedgehog, queue<pair<int, int>>& qWater);
	bool isInside(vector<vector<char>>& vvMap, pair<int, int> pPos);
	void printMap(vector<vector<char>>& vvMap);
	void solution(void)
	{
		int nRow{};
		int nColumn{};
		vector<vector<char>> vvMap{};
		queue<pair<int, int>> qHedgehog{};
		queue<pair<int, int>> qWater{};

		inputData(nRow, nColumn, vvMap, qHedgehog, qWater);

		BFS(vvMap, qHedgehog, qWater);

	}

	void inputData(int& nRow, int& nColumn, vector<vector<char>>& vvMap, queue<pair<int, int>>& qHedgehog, queue<pair<int, int>>& qWater)
	{
		cin >> nRow;
		cin >> nColumn;

		vvMap.resize(nRow, vector<char>(nColumn, 0));

		for (int i = 0; i < nRow; i++)
		{
			for (int j = 0; j < nColumn; j++)
			{
				char cTemp{};
				cin >> cTemp;

				if (cTemp == 'S')
					qHedgehog.push({ i,j });
				else if (cTemp == '*')
					qWater.push({ i,j });

				vvMap[i][j] = cTemp;

			}
		}
	}

	void BFS(vector<vector<char>>& vvMap, queue<pair<int, int>>& qHedgehog, queue<pair<int, int>>& qWater)
	{
		int arrDir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
		queue<pair<int, int>> qNextHedgehog{};
		queue<pair<int, int>> qNextWater{};

		queue<pair<int, int>>* pqHedgehog = &qHedgehog;
		queue<pair<int, int>>* pqNextHedgehog = &qNextHedgehog;

		queue<pair<int, int>>* pqWater = &qWater;
		queue<pair<int, int>>* pqNextWater = &qNextWater;

		int nTime = 0;

		while (!pqHedgehog->empty())
		{
			while (!pqWater->empty())
			{
				pair<int, int> pWaterPos = pqWater->front();
				pqWater->pop();

				for (int i = 0; i < 4; i++)
				{
					pair<int, int> pNextWaterPos = { pWaterPos.first + arrDir[i][0], pWaterPos.second + arrDir[i][1] };

					if (isInside(vvMap, pNextWaterPos) && vvMap[pNextWaterPos.first][pNextWaterPos.second] == '.')
					{
						vvMap[pNextWaterPos.first][pNextWaterPos.second] = '*';
						pqNextWater->push(pNextWaterPos);
					}
				}
			}

			while (!pqHedgehog->empty())
			{
				pair<int, int> pHedgehogPos = pqHedgehog->front();
				pqHedgehog->pop();

				for (int i = 0; i < 4; i++)
				{
					pair<int, int> pNextHedgehogPos = { pHedgehogPos.first + arrDir[i][0], pHedgehogPos.second + arrDir[i][1] };

					if (isInside(vvMap, pNextHedgehogPos))
					{
						if (vvMap[pNextHedgehogPos.first][pNextHedgehogPos.second] == 'D')
						{
							cout << nTime + 1;
							return;
						}
						else if (vvMap[pNextHedgehogPos.first][pNextHedgehogPos.second] == '.')
						{
							vvMap[pNextHedgehogPos.first][pNextHedgehogPos.second] = 'S';
							pqNextHedgehog->push(pNextHedgehogPos);
						}
					}
				}

			}
			//print
			//printMap(vvMap);
			swap(pqWater, pqNextWater);
			swap(pqHedgehog, pqNextHedgehog);
			nTime++;
		}

		cout << "KAKTUS";
	}

	bool isInside(vector<vector<char>>& vvMap, pair<int, int> pPos)
	{
		if (pPos.first >= 0 && pPos.first < vvMap.size() && pPos.second >= 0 && pPos.second < vvMap[0].size())
			return true;

		return false;
	}

	void printMap(vector<vector<char>>& vvMap)
	{
		for (int i = 0; i < vvMap.size(); i++)
		{
			for (int j = 0; j < vvMap[0].size(); j++)
			{
				cout << vvMap[i][j];
			}
			cout << endl;
		}
		cout << endl;

	}

}