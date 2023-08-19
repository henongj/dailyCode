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

//https://www.acmicpc.net/problem/16236
//아기 상어

//https://www.acmicpc.net/problem/16236
//아기 상어
namespace acmicpc_16236
{
	using namespace std;

	struct sInfo
	{
		int nY;
		int nX;
		int nTime;
	};
	void solution(void);
	void inputData(int& nSize, vector<vector<int>>& vvMap, pair<int, int>& pSharkPos);
	bool isInside(int nX, int nY, int nSize);
	void resetVisited(vector<vector<bool>>& vvVisited, int nSize);
	void printMap(vector<vector<int>>& vvMap, int nSize);

	void solution(void)
	{
		int nSize{};
		vector<vector<int>> vvMap{};
		pair<int, int> pSharkPos{};

		int nSharkSize{};
		int nEatCount{};
		int nTime{};

		// 상 좌 우 하
		int arrDir[4][2] = { {-1,0}, {0,-1}, {0,1}, {1,0} };
		queue<sInfo> qInfo{};
		vector<vector<bool>> vvVisited{};

		inputData(nSize, vvMap, pSharkPos);
		vvVisited.resize(nSize);
		for (int i = 0; i < nSize; ++i)
			vvVisited[i].resize(nSize);

		nSharkSize = 2;
		nEatCount = 0;
		nTime = 0;

		vvMap[pSharkPos.first][pSharkPos.second] = 0;
		qInfo.push({ pSharkPos.first, pSharkPos.second, nTime });

		//bfs
		while (!qInfo.empty())
		{
			sInfo sCurrentInfo = qInfo.front();
			qInfo.pop();

			int nCurrentY = sCurrentInfo.nY;
			int nCurrentX = sCurrentInfo.nX;
			int nCurrentTime = sCurrentInfo.nTime;

			if (vvMap[nCurrentY][nCurrentX] != 0 && vvMap[nCurrentY][nCurrentX] < nSharkSize)
			{
				vvMap[nCurrentY][nCurrentX] = 0;
				nEatCount++;
				nTime = nCurrentTime;

				cout << "\neat : " << nCurrentY << " " << nCurrentX << " " << nCurrentTime << " " << nSharkSize << endl;
				printMap(vvMap, nSize);

				if (nEatCount == nSharkSize)
				{
					nSharkSize++;
					nEatCount = 0;
					cout << "size up : " << nSharkSize << endl;
				}

				resetVisited(vvVisited, nSize);
				while (!qInfo.empty())
					qInfo.pop();
			}

			for (int i = 0; i < 4; ++i)
			{
				int nNextY = nCurrentY + arrDir[i][0];
				int nNextX = nCurrentX + arrDir[i][1];

				if (isInside(nNextX, nNextY, nSize) && !vvVisited[nNextY][nNextX] && vvMap[nNextY][nNextX] <= nSharkSize)
				{
					vvVisited[nNextY][nNextX] = true;
					qInfo.push({ nNextY, nNextX, nCurrentTime + 1 });
				}
			}
		}

		cout << nTime << endl;




	}

	void inputData(int& nSize, vector<vector<int>>& vvMap, pair<int, int>& pSharkPos)
	{
		cin >> nSize;
		vvMap.resize(nSize);
		for (int i = 0; i < nSize; ++i)
		{
			vvMap[i].resize(nSize);
			for (int j = 0; j < nSize; ++j)
			{
				cin >> vvMap[i][j];

				if (vvMap[i][j] == 9)
				{
					pSharkPos.first = i;
					pSharkPos.second = j;
				}

			}
		}
	}

	bool isInside(int nX, int nY, int nSize)
	{
		if (nX >= 0 && nX < nSize && nY >= 0 && nY < nSize)
			return true;
		return false;
	}

	void resetVisited(vector<vector<bool>>& vvVisited, int nSize)
	{
		for (int i = 0; i < nSize; ++i)
		{
			for (int j = 0; j < nSize; ++j)
			{
				vvVisited[i][j] = false;
			}
		}
	}

	void printMap(vector<vector<int>>& vvMap, int nSize)
	{
		cout << endl;
		for (int i = 0; i < nSize; ++i)
		{
			for (int j = 0; j < nSize; ++j)
			{
				cout << vvMap[i][j] << " ";
			}
			cout << endl;
		}
	}

}
