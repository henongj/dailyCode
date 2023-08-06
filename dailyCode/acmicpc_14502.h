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

namespace acmicpc_14502{

	//https://www.acmicpc.net/problem/14502
	//연구소
	void solution_acmicpc14502(void);
	void inputData_acmicpc14502(int& nRow, int& nColumn, std::vector<std::vector<int>>& vvMap, std::vector<std::pair<int, int>>& vVirus);
	void setWall(std::vector<std::vector<int>>& vvCopyMap, int nWallCount, int nMaxWallCount, std::pair<int, int> pPosition, const std::vector<std::pair<int, int>>& vVirus, std::queue<std::pair<int, int>>& qVirusSpread, int& nSafeArea);
	std::queue<std::pair<int, int>>& spreadVirus(std::vector<std::vector<int>>& vvCopyMap, const std::vector<std::pair<int, int>>& vVirus, std::queue<std::pair<int, int>>& qVirus);
	int countSafeArea(std::vector<std::vector<int>>& vvCopyMap);
	int mainSpace_acmicpc14502(void)
	{
		solution_acmicpc14502();

		return 0;
	}
	void solution_acmicpc14502(void)
	{
		using namespace std;

		int nRow{};
		int nColumn{};
		vector<vector<int>> vvMap{};
		vector<pair<int, int>> vVirus{};
		std::queue<std::pair<int, int>> qVirus{};
		vector<vector<int>> vvMapCopy{};
		vector<vector<bool>> vvMapVisited{};
		int nMaxSafeArea{};
		int nWallCount{};

		inputData_acmicpc14502(nRow, nColumn, vvMap, vVirus);
		vvMapCopy = vvMap;
		vvMapVisited.resize(nRow, vector<bool>(nColumn, false));

		setWall(vvMapCopy, nWallCount, 3, { 0,0 }, vVirus, qVirus, nMaxSafeArea);

		cout << nMaxSafeArea << "\n";

	}
	void inputData_acmicpc14502(int& nRow, int& nColumn, std::vector<std::vector<int>>& vvMap, std::vector<std::pair<int, int>>& vVirus)
	{
		using namespace std;

		cin >> nRow >> nColumn;
		vvMap.resize(nRow, vector<int>(nColumn, 0));
		for (int i = 0; i < nRow; ++i)
		{
			for (int j = 0; j < nColumn; ++j)
			{
				cin >> vvMap[i][j];
				if (vvMap[i][j] == 2)
					vVirus.push_back({ i,j });
			}
		}
	}
	void setWall(std::vector<std::vector<int>>& vvCopyMap, int nWallCount, int nMaxWallCount, std::pair<int, int> pPosition, const std::vector<std::pair<int, int>>& vVirus, std::queue<std::pair<int, int>>& qVirusSpread, int& nSafeArea)
	{
		using namespace std;
		const int nEmpty = 0;
		const int nWall = 1;

		int nRow = pPosition.first;
		int nColumn = pPosition.second;

		int nNextRow = nRow;
		int nNextColumn = nColumn;
		if (nNextColumn == vvCopyMap[0].size())
		{
			nNextColumn = 0;
			nNextRow++;
		}

		while (nNextRow != vvCopyMap.size())
		{
			if (vvCopyMap[nNextRow][nNextColumn] == nEmpty)
			{
				vvCopyMap[nNextRow][nNextColumn] = nWall;
				nWallCount++;

				if (nWallCount < nMaxWallCount)
					setWall(vvCopyMap, nWallCount, nMaxWallCount, { nNextRow , nNextColumn + 1 }, vVirus, qVirusSpread, nSafeArea);
				else
				{
					//바이러스를 퍼트린다.
					spreadVirus(vvCopyMap, vVirus, qVirusSpread);

					//안전 영역을 구한다.
					nSafeArea = max(nSafeArea, countSafeArea(vvCopyMap));

					//바이러스를 초기 상태로 되돌린다.
					while (!qVirusSpread.empty())
					{
						pair<int, int> pVirus = qVirusSpread.front();
						qVirusSpread.pop();

						int nRow = pVirus.first;
						int nColumn = pVirus.second;

						vvCopyMap[nRow][nColumn] = 0;
					}
					for (int k = 0; k < vVirus.size(); k++)
					{
						qVirusSpread.push(vVirus[k]);
						vvCopyMap[vVirus[k].first][vVirus[k].second] = 2;
					}
				}
				vvCopyMap[nNextRow][nNextColumn] = nEmpty;
				nWallCount--;
			}

			nNextColumn++;
			if (nNextColumn == vvCopyMap[0].size())
			{
				nNextColumn = 0;
				nNextRow++;
			}
		}

	}
	std::queue<std::pair<int, int>>& spreadVirus(std::vector<std::vector<int>>& vvCopyMap, const std::vector<std::pair<int, int>>& vVirus, std::queue<std::pair<int, int>>& qVirus)
	{
		using namespace std;

		queue<pair<int, int>> qSpreadVirus{};
		vector<vector<bool>> vvMapVisited{};
		int arrDir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

		vvMapVisited.resize(vvCopyMap.size(), vector<bool>(vvCopyMap[0].size(), false));

		for (int i = 0; i < vVirus.size(); ++i)
		{
			qSpreadVirus.push(vVirus[i]);
			vvMapVisited[vVirus[i].first][vVirus[i].second] = true;
		}

		while (!qSpreadVirus.empty())
		{
			std::pair<int, int> pVirus = qSpreadVirus.front();
			qSpreadVirus.pop();

			int nRow = pVirus.first;
			int nColumn = pVirus.second;
			vvCopyMap[nRow][nColumn] = 2;
			qVirus.push(pVirus);

			for (int i = 0; i < 4; ++i)
			{
				int nNextRow = nRow + arrDir[i][0];
				int nNextColumn = nColumn + arrDir[i][1];

				if (0 <= nNextRow && nNextRow < vvCopyMap.size() && 0 <= nNextColumn && nNextColumn < vvCopyMap[nNextRow].size())
				{
					if (vvCopyMap[nNextRow][nNextColumn] == 0 && !vvMapVisited[nNextRow][nNextColumn])
					{
						qSpreadVirus.push({ nNextRow,nNextColumn });
						vvMapVisited[nNextRow][nNextColumn] = true;
					}
				}
			}
		}

		return qVirus;

	}
	int countSafeArea(std::vector<std::vector<int>>& vvCopyMap)
	{
		using namespace std;

		int nSafeArea{};

		for (int i = 0; i < vvCopyMap.size(); ++i)
		{
			for (int j = 0; j < vvCopyMap[i].size(); ++j)
			{
				if (vvCopyMap[i][j] == 0)
					nSafeArea++;
			}
		}

		return nSafeArea;

	}
}
