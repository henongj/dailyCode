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

//https://www.acmicpc.net/problem/1520
namespace acmicpc_1520_TLE
{
	using namespace std;
	bool isInside(vector<vector<int>>& vvMap, pair<int, int> pPos);
	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap);
	void DFS(vector<vector<int>>& vvMap, pair<int, int> pPos, vector<vector<int>>& vvDP);
	void BFS(vector<vector<int>>& vvMap, vector<vector<int>>& vvDP);
	void printMatrix(vector<vector<int>>& vvMatrix);
	void solution(void);

	void solution(void)
	{
		int nRow{};
		int nColumn{};
		vector<vector<int>> vvMap{};
		vector<vector<int>> vvDP{};
		inputData(nRow, nColumn, vvMap);

		vvDP.resize(nRow, vector<int>(nColumn, 0));
		//DPS(vvMap, { 0,0 }, vvDP);
		BFS(vvMap, vvDP);

		//printMatrix(vvDP);

		cout << vvDP[nRow - 1][nColumn - 1] << endl;
	}


	bool isInside(vector<vector<int>>& vvMap, pair<int, int> pPos)
	{
		int nRow = pPos.first;
		int nColumn = pPos.second;

		if (0 <= nRow && nRow < vvMap.size() && 0 <= nColumn && nColumn < vvMap[0].size())
			return true;
		return false;
	}

	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap)
	{
		cin >> nRow >> nColumn;
		vvMap.resize(nRow, vector<int>(nColumn));
		for (auto& row : vvMap)
		{
			for (auto& column : row)
				cin >> column;
		}
	}

	void DFS(vector<vector<int>>& vvMap, pair<int, int> pPos, vector<vector<int>>& vvDP)
	{
		int arrDir[4][2]{ {0,1},{1,0},{0,-1},{-1,0} };
		int nRow = pPos.first;
		int nColumn = pPos.second;

		vvDP[nRow][nColumn] += 1;

		if (nRow == vvMap.size() - 1 && nColumn == vvMap[0].size() - 1)
			return;

		for (int i = 0; i < 4; ++i)
		{
			int nNextRow = nRow + arrDir[i][0];
			int nNextColumn = nColumn + arrDir[i][1];

			// 안이고 내리막길			
			if (isInside(vvMap, { nNextRow,nNextColumn }) && vvMap[nRow][nColumn] > vvMap[nNextRow][nNextColumn])
			{
				DFS(vvMap, { nNextRow,nNextColumn }, vvDP);
			}
		}

	}

	void BFS(vector<vector<int>>& vvMap, vector<vector<int>>& vvDP)
	{
		int arrDir[4][2]{ {0,1},{1,0},{0,-1},{-1,0} };
		queue<pair<int, int>> qPos{};

		qPos.push({ 0,0 });

		while (!qPos.empty())
		{
			pair<int, int> pPos = qPos.front();
			qPos.pop();

			int nRow = pPos.first;
			int nColumn = pPos.second;

			vvDP[nRow][nColumn] += 1;

			for (int i = 0; i < 4; ++i)
			{
				int nNextRow = nRow + arrDir[i][0];
				int nNextColumn = nColumn + arrDir[i][1];

				// 안이고 내리막길			
				if (isInside(vvMap, { nNextRow,nNextColumn }) && vvMap[nRow][nColumn] > vvMap[nNextRow][nNextColumn])
				{
					qPos.push({ nNextRow,nNextColumn });
				}
			}
		}
	}

	void printMatrix(vector<vector<int>>& vvMatrix)
	{
		for (auto& row : vvMatrix)
		{
			for (auto& column : row)
				cout << column << " ";
			cout << endl;
		}
	}


}

