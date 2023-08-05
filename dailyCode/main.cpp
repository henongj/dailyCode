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

//https://www.acmicpc.net/problem/14502
//연구소
void solution_acmicpc14502(void);
void inputData_acmicpc14502(int& nRow, int& nColumn, std::vector<std::vector<int>>& vvMap, std::vector<std::pair<int,int>>& vVirus);
void setWall(std::vector<std::vector<int>>& vvCopyMap, int nWallCount, int nMaxWallCount, std::pair<int, int> pPosition, const std::vector<std::pair<int, int>>& vVirus, int& nSafeArea);
std::queue<std::pair<int,int>>& spreadVirus(std::vector<std::vector<int>>& vvCopyMap, const std::vector<std::pair<int,int>>& vVirus, std::queue<std::pair<int, int>>& qVirus);
int countSafeArea(std::vector<std::vector<int>>& vvCopyMap);
int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
	vector<vector<int>> vvMapCopy{};
	vector<vector<bool>> vvMapVisited{};
	std::queue<std::pair<int, int>> qVirus{};
	int nMaxSafeArea{};
	int nWallCount{};

	inputData_acmicpc14502(nRow, nColumn, vvMap, vVirus);
	vvMapCopy = vvMap;
	vvMapVisited.resize(nRow, vector<bool>(nColumn, false));

	setWall(vvMapCopy, nWallCount, 3, { 0,0 }, vVirus, nMaxSafeArea);

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

void setWall(std::vector<std::vector<int>>& vvCopyMap, int nWallCount, int nMaxWallCount, std::pair<int, int> pPosition, const std::vector<std::pair<int, int>>& vVirus, int& nSafeArea)
{
	using namespace std;
	const int nEmpty = 0;

	int nRow = pPosition.first;
	int nColumn = pPosition.second;

	for (int i = nRow; i < vvCopyMap.size(); i++)
	{
		for (int j = nColumn + 1; j < vvCopyMap[i].size(); j++)
		{
			if (vvCopyMap[i][j] != nEmpty)
				continue;

			vvCopyMap[i][j] = 1;
			nWallCount++;

			if (nWallCount < nMaxWallCount)
			{
				setWall(vvCopyMap, nWallCount, nMaxWallCount, { i , j }, vVirus, nSafeArea);
				vvCopyMap[i][j] = 0;
				nWallCount--;
			}
			else
			{
				//바이러스를 퍼트린다.
				queue<pair<int, int>> qVirus{};
				spreadVirus(vvCopyMap, vVirus, qVirus);

				//안전 영역을 구한다.
				nSafeArea = max(nSafeArea, countSafeArea(vvCopyMap));

				//바이러스를 퍼트린 곳을 되돌린다.
				while (!qVirus.empty())
				{
					pair<int, int> pVirus = qVirus.front();
					qVirus.pop();

					int nRow = pVirus.first;
					int nColumn = pVirus.second;

					vvCopyMap[nRow][nColumn] = 0;
				}
			}
		}
	}

}

std::queue<std::pair<int, int>>& spreadVirus(std::vector<std::vector<int>>& vvCopyMap, const std::vector<std::pair<int,int>>& vVirus, std::queue<std::pair<int,int>>& qVirus)
{
	using namespace std;

	queue<pair<int,int>> qSpreadVirus{};
	vector<vector<bool>> vvMapVisited{};
	int arrDir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	vvMapVisited.resize(vvCopyMap.size(), vector<bool>(vvCopyMap[0].size(), false));

	for (int i = 0; i < vVirus.size(); ++i)
	{
		qSpreadVirus.push(vVirus[i]);
		vvMapVisited[vVirus[i].first][vVirus[i].second] = true;
	}

	while (!qVirus.empty())
	{
		std::pair<int,int> pVirus = qSpreadVirus.front();
		qSpreadVirus.pop();

		int nRow = pVirus.first;
		int nColumn = pVirus.second;
		qVirus.push(pVirus);

		vvCopyMap[nRow][nColumn] = 2;

		for (int i = 0; i < 4; ++i)
		{
			int nNextRow = nRow + arrDir[i][0];
			int nNextColumn = nColumn + arrDir[i][1];

			if (0 <= nNextRow && nNextRow < vvCopyMap.size() && 0 <= nNextColumn && nNextColumn < vvCopyMap[nNextRow].size())
			{
				if (vvCopyMap[nNextRow][nNextColumn] == 0 && !vvMapVisited[nNextRow][nNextColumn])
				{
					qVirus.push({ nNextRow,nNextColumn });
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
