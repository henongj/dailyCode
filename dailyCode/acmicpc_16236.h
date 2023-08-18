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
namespace acmicpc_16236
{
	using namespace std;

	class c_Map
	{
	private:
		vector<vector<int>> m_vvMap{};
		int m_nSize{};

		vector<vector<bool>> m_vvVisit{};
		priority_queue<pair<int, int>> m_pqFish{};
		pair<int, int> m_pSharkPosition{};

	public:
		c_Map() = default;
		~c_Map() = default;

		c_Map& operator=(const c_Map& sSrc) = delete;
		c_Map(const c_Map& sSrc) = delete;

		void init(int nSize);
		void inputData(void);

		// visit
		bool isVisited(pair<int, int> pPosition);
		void visit(pair<int, int> pPosition)
		{
			m_vvVisit[pPosition.first][pPosition.second] = true;
		}

		// get
		pair<int, int>& getSharkPosition(void)
		{
			return m_pSharkPosition;
		}
		pair<int, int> getFishPosition(void)
		{
			pair<int, int> pPosition = m_pqFish.top();
			m_pqFish.pop();
			return pPosition;
		}
		vector<vector<int>>& getMap(void)
		{
			return m_vvMap;
		}
		int getSize(void)
		{
			return m_nSize;
		}

		// set
		void setSharkPosition(pair<int, int>& pPosition)
		{
			m_vvMap[m_pSharkPosition.first][m_pSharkPosition.second] = 0;

			m_pSharkPosition = pPosition;

			m_vvMap[m_pSharkPosition.first][m_pSharkPosition.second] = 9;
		}

		// else
		void popFish(void)
		{
			m_pqFish.pop();
		}
		void resetVisit(void);
		bool isLeftFish(void)
		{
			return !m_pqFish.empty();
		}
	};
	class c_BabyShark
	{
	private:
		pair<int, int> m_pPosition{};
		int m_nSize{};
		int m_nEatCount{};
		int m_nTime{};

	public:
		c_BabyShark() = default;
		~c_BabyShark() = default;

		c_BabyShark& operator=(const c_BabyShark& sSrc) = delete;
		c_BabyShark(const c_BabyShark& sSrc) = delete;

		void init(pair<int, int> pPosition);
		void eatFish(void);
		bool move(c_Map& cMap);

		// get
		pair<int, int>& getPosition(void)
		{
			return m_pPosition;
		}
		int getTime(void)
		{
			return m_nTime;
		}

	};
	void solution(void);

	void solution(void)
	{
		c_BabyShark cBabyShark{};
		c_Map cMap{};

		int nSize = 0;

		cin >> nSize;
		cMap.init(nSize);
		cMap.inputData();

		cBabyShark.init(cMap.getSharkPosition());

		while (cMap.isLeftFish())
		{
			if (cBabyShark.move(cMap) == false)
				break;
		}

		cout << cBabyShark.getTime() << endl;

	}
	void c_BabyShark::init(pair<int, int> pPosition)
	{
		m_pPosition = pPosition;
		m_nSize = 2;
		m_nEatCount = 0;
		m_nTime = 0;
	}
	void c_BabyShark::eatFish(void)
	{
		m_nEatCount++;
		if (m_nEatCount == m_nSize)
		{
			m_nSize++;
			m_nEatCount = 0;
		}
	}
	bool c_BabyShark::move(c_Map& cMap)
	{
		pair<int, int> pPosition = m_pPosition;
		pair<int, int> pNextPosition = cMap.getFishPosition();
		vector<vector<int>>& vvMap = cMap.getMap();
		int nFishSize = vvMap[pNextPosition.first][pNextPosition.second];

		if (nFishSize >= m_nSize)
			return false;

		int nTime = 0;
		cMap.resetVisit(); // visit 초기화
		cMap.visit(pPosition); // 현재 위치 visit
		int arrDir[4][2] = { {-1,0},{0,1},{0,-1},{1,0} };

		// queue를 이용한 BFS로 수정해야함
		while (pPosition.first != pNextPosition.first || pPosition.second != pNextPosition.second)
		{
			// vvMap[row][col]에 적힌 숫자가 m_nSize이하여야 이동 가능
			// 이동 가능한 위치가 여럿이면 위, 오른쪽, 왼쪽, 아래 순서로 이동

			// 4방향 탐색
			for (int i = 0; i < 4; i++)
			{
				int nRow = pPosition.first + arrDir[i][0];
				int nCol = pPosition.second + arrDir[i][1];

				// 범위 내이고 방문하지 않음
				if (0 <= nRow && nRow < cMap.getSize() && 0 <= nCol && nCol < cMap.getSize() && cMap.isVisited({ nRow,nCol }) == false)
				{
					// 이동 가능한 위치이면 이동
					if (vvMap[nRow][nCol] <= m_nSize)
					{
						pPosition = { nRow,nCol };
						cMap.visit(pPosition);
						nTime++;

						// 이동했으면 다른 방향은 탐색할 필요 없음
						i = 4;
					}
				}
			}
		}

		m_pPosition = pPosition; // 상어 위치 갱신
		cMap.setSharkPosition(m_pPosition); // 상어 위치 갱신

		m_nTime += nTime; // 시간 갱신
		eatFish(); // 물고기 먹음
		cMap.popFish(); // 물고기 제거
		return true;
	}
	void c_Map::init(int nSize)
	{
		m_nSize = nSize;
		m_vvMap.resize(nSize, vector<int>(nSize, 0));
		m_vvVisit.resize(nSize, vector<bool>(nSize, false));
	}
	void c_Map::inputData(void)
	{
		for (int r = 0; r < m_nSize; r++)
		{
			for (int c = 0; c < m_nSize; c++)
			{
				cin >> m_vvMap[r][c];

				if (m_vvMap[r][c] == 9)
					m_pSharkPosition = { r,c };
				else if (m_vvMap[r][c] != 0)//not empty and not shark
					m_pqFish.push({ r,c });
			}
		}
	}
	void c_Map::resetVisit(void)
	{
		for (int r = 0; r < m_nSize; r++)
		{
			for (int c = 0; c < m_nSize; c++)
				m_vvVisit[r][c] = false;
		}
	}
	bool c_Map::isVisited(pair<int, int> pPosition)
	{
		if (m_vvVisit[pPosition.first][pPosition.second])
			return true;
		return false;
	}
}
