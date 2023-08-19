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

//https://www.acmicpc.net/problem/16236
//�Ʊ� ���
namespace acmicpc_16236
{
	using namespace std;

	struct sInfo
	{
		int nX;
		int nY;
		int nDistance;
	};
	void solution(void);
	void inputData(int& nSize, vector<vector<int>>& vvMap, pair<int, int>& pSharkPos);
	bool isInside(int nX, int nY, int nSize);


	void solution(void)
	{
		int nSize = 0;
		vector<vector<int>> vvMap;
		pair<int, int> pSharkPos{};
		inputData(nSize, vvMap, pSharkPos);

		// �� �� �� ��
		int arrDir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
		int nSharkEatCount = 0;
		int nTime = 0;
		int nSharkSize = 2;

		sInfo sSharkInfo{};
		sSharkInfo.nX = pSharkPos.first;
		sSharkInfo.nY = pSharkPos.second;
		sSharkInfo.nDistance = 0;

		while (true)
		{
			vector<vector<bool>> vvVisited(nSize, vector<bool>(nSize, false));
			queue<sInfo> qShark;
			qShark.push(sSharkInfo);
			vvVisited[sSharkInfo.nX][sSharkInfo.nY] = true;

			vector<sInfo> vFish;
			int nMinDistance = 99999999;
			while (!qShark.empty())
			{
				sInfo sCurInfo = qShark.front();
				qShark.pop();

				int nRow = sCurInfo.nX;
				int nCol = sCurInfo.nY;
				int nTime = sCurInfo.nDistance;

				if (nTime > nMinDistance)
					break;

				for (int i = 0; i < 4; ++i)
				{
					int nNextX = nRow + arrDir[i][0];
					int nNextY = nCol + arrDir[i][1];

					// ���� ���̰ų� �̹� �湮�߰ų� ���� ũ�� �н�
					if (isInside(nNextX, nNextY, nSize) == false || vvVisited[nNextX][nNextY] == true || vvMap[nNextX][nNextY] > nSharkSize)
						continue;

					// ���� �� �ִ� ������ �԰�, ��� ��ġ �̵�, ��� ũ�� ������ �� ������ ����, visit �ʱ�ȭ, �ð� ����
					if (vvMap[nNextX][nNextY] != 0 && vvMap[nNextX][nNextY] < nSharkSize)
					{
						vvMap[nNextX][nNextY] = 0;
						nSharkEatCount++;
						if (nSharkEatCount == nSharkSize)
						{
							nSharkSize++;
							nSharkEatCount = 0;
						}



						
					}

					// ���� Ž�� ��ǥ ť�� �ֱ�
					sInfo sNextInfo{};
					sNextInfo.nX = nNextX;
					sNextInfo.nY = nNextY;
					sNextInfo.nDistance = sCurInfo.nDistance + 1;
					qShark.push(sNextInfo);
					vvVisited[nNextX][nNextY] = true;
				}
			}


		}



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

}



int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	return 0;
}

