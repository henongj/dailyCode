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

//https://www.acmicpc.net/problem/14499
//주사위 굴리기
namespace acmicpc_14499
{
	using namespace std;

	class c_Dice
	{
	private:
		int m_nTop{};
		int m_nBottom{};
		int m_nLeft{};
		int m_nRight{};
		int m_nFront{};
		int m_nBack{};
		pair<int, int> m_posDice{};

	private:
		void rollDiceEast(void);
		void rollDiceWest(void);
		void rollDiceNorth(void);
		void rollDiceSouth(void);

	public:
		c_Dice() = default;
		~c_Dice() = default;

		void setDice(pair<int, int>& posDice);
		void setBottomNumber(int nBottom);
		int getBottomNumber(void);
		int getTopNumber(void);
		void rollDice(int nCommand);
		pair<int, int>& getPosDice(void);

	};

	void solution(void);
	void inputData(int& nRow, int& nColumn, pair<int, int>& posDice, int& nCommand, vector<vector<int>>& vvMap, vector<int>& vCommand);
	bool isInside(int nRow, int nColumn, vector<vector<int>>& vvMap);
	void solution(void)
	{
		int nRow{};
		int nColumn{};
		pair<int, int> posDice{};
		int nCommand{};
		c_Dice cDice{};
		int arrDir[5][2] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} };

		vector<vector<int>> vvMap{};
		vector<int> vCommand{};
		inputData(nRow, nColumn, posDice, nCommand, vvMap, vCommand);

		cDice.setDice(posDice);

		for (int i = 0; i < nCommand; i++)
		{
			int nNextRow = cDice.getPosDice().first + arrDir[vCommand[i]][0];
			int nNextColumn = cDice.getPosDice().second + arrDir[vCommand[i]][1];

			if (isInside(nNextRow, nNextColumn, vvMap))
			{
				cDice.rollDice(vCommand[i]);
				if (vvMap[nNextRow][nNextColumn])
				{
					cDice.setBottomNumber(vvMap[nNextRow][nNextColumn]);
					vvMap[nNextRow][nNextColumn] = 0;
				}
				else
				{
					vvMap[nNextRow][nNextColumn] = cDice.getBottomNumber();
				}

				cout << cDice.getTopNumber() << "\n";

			}
		}


	}

	void inputData(int& nRow, int& nColumn, pair<int, int>& posDice, int& nCommand, vector<vector<int>>& vvMap, vector<int>& vCommand)
	{
		cin >> nRow;
		cin >> nColumn;
		cin >> posDice.first;
		cin >> posDice.second;
		cin >> nCommand;
		vCommand.resize(nCommand);

		vvMap.resize(nRow);
		for (int i = 0; i < nRow; i++)
			vvMap[i].resize(nColumn);

		for (int i = 0; i < nRow; i++)
			for (int j = 0; j < nColumn; j++)
				cin >> vvMap[i][j];

		for (int i = 0; i < nCommand; i++)
			cin >> vCommand[i];
	}
	bool isInside(int nRow, int nColumn, vector<vector<int>>& vvMap)
	{
		if (nRow >= 0 && nRow < vvMap.size() && nColumn >= 0 && nColumn < vvMap[0].size())
			return true;
		return false;
	}

	void c_Dice::rollDiceEast(void)
	{
		// top이 right로
		int nTemp = m_nTop;
		m_nTop = m_nRight;
		m_nRight = m_nBottom;
		m_nBottom = m_nLeft;
		m_nLeft = nTemp;

		m_posDice.second++;
	}
	void c_Dice::rollDiceWest(void)
	{
		// top이 left로
		int nTemp = m_nTop;
		m_nTop = m_nLeft;
		m_nLeft = m_nBottom;
		m_nBottom = m_nRight;
		m_nRight = nTemp;

		m_posDice.second--;
	}
	void c_Dice::rollDiceNorth(void)
	{
		// top이 back으로 
		int nTemp = m_nTop;
		m_nTop = m_nBack;
		m_nBack = m_nBottom;
		m_nBottom = m_nFront;
		m_nFront = nTemp;

		m_posDice.first--;
	}
	void c_Dice::rollDiceSouth(void)
	{
		// top이 front로
		int nTemp = m_nTop;
		m_nTop = m_nFront;
		m_nFront = m_nBottom;
		m_nBottom = m_nBack;
		m_nBack = nTemp;

		m_posDice.first++;
	}
	void c_Dice::setDice(pair<int, int>& posDice)
	{
		m_posDice = posDice;

		m_nTop = 0;
		m_nBottom = 0;
		m_nLeft = 0;
		m_nRight = 0;
		m_nFront = 0;
		m_nBack = 0;

	}
	void c_Dice::setBottomNumber(int nBottom)
	{
		m_nBottom = nBottom;
	}
	int c_Dice::getBottomNumber(void)
	{
		return m_nBottom;
	}
	int c_Dice::getTopNumber(void)
	{
		return m_nTop;
	}
	void c_Dice::rollDice(int nCommand)
	{
		switch (nCommand)
		{
		case 1:
			rollDiceEast();
			break;
		case 2:
			rollDiceWest();
			break;
		case 3:
			rollDiceNorth();
			break;
		case 4:
			rollDiceSouth();
			break;
		default:
			break;
		}
	}
	pair<int, int>& c_Dice::getPosDice(void)
	{
		return m_posDice;
	}
}
