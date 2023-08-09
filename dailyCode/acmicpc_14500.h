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

//https://www.acmicpc.net/problem/14500
//테트로미노
namespace acmicpc_14500 {
	using namespace std;

	void solution(void);
	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap);
	void inputTetromino(vector<vector<pair<int, int>>>& vvTetromino);

	void solution(void)
	{
		int nRow{};
		int nColumn{};
		vector<vector<int>> vvMap{};

		vector<vector<pair<int, int>>> vvTetromino{};

		inputData(nRow, nColumn, vvMap);
		vvTetromino.reserve(19);

		inputTetromino(vvTetromino);

		int nMaxSum{};
		for (int i = 0; i < nRow; ++i)
		{
			for (int j = 0; j < nColumn; ++j)
			{
				for (int k = 0; k < vvTetromino.size(); ++k)
				{
					int nSum{};
					for (int l = 0; l < 4; ++l)
					{
						int nRowIdx = i + vvTetromino[k][l].first;
						int nColumnIdx = j + vvTetromino[k][l].second;

						if (nRowIdx < 0 || nRowIdx >= nRow || nColumnIdx < 0 || nColumnIdx >= nColumn)
							break;

						nSum += vvMap[nRowIdx][nColumnIdx];
					}

					nMaxSum = max(nMaxSum, nSum);
				}
			}
		}

		cout << nMaxSum << endl;


	}


	void inputData(int& nRow, int& nColumn, vector<vector<int>>& vvMap)
	{
		cin >> nRow;
		cin >> nColumn;

		vvMap.resize(nRow, vector<int>(nColumn, 0));

		for (int i = 0; i < nRow; ++i)
		{
			for (int j = 0; j < nColumn; ++j)
				cin >> vvMap[i][j];
		}
	}
	void inputTetromino(vector<vector<pair<int, int>>>& vvTetromino)
	{
		// ㅡ 
		vvTetromino.push_back({ {0,0},{0,1},{0,2},{0,3} });
		// |
		vvTetromino.push_back({ {0,0},{1,0},{2,0},{3,0} });
		// ㅁ
		vvTetromino.push_back({ {0,0},{0,1},{1,0},{1,1} });
		// ㅗ
		vvTetromino.push_back({ {0,0},{1,0},{1,-1},{1,1} });
		// ㅜ
		vvTetromino.push_back({ {0,0},{0,1},{1,1},{0,2} });
		// ㅓ
		vvTetromino.push_back({ {0,0},{1,0},{2,0},{1,-1} });
		// ㅏ
		vvTetromino.push_back({ {0,0},{1,0},{2,0},{1,1} });
		// ㄴ 2종류
		vvTetromino.push_back({ {0,0},{1,0},{1,1},{1,2} });
		vvTetromino.push_back({ {0,0},{1,0},{2,0},{2,1} });
		// ㄴ의 대칭 2종류
		vvTetromino.push_back({ {0,0},{0,1},{0,2},{-1,2} });
		vvTetromino.push_back({ {0,0},{0,1},{-1,1},{-2,1} });
		// ㄱ 2종류
		vvTetromino.push_back({ {0,0},{0,1},{0,2},{1,2} });
		vvTetromino.push_back({ {0,0},{0,1},{1,1},{2,1} });
		// ㄱ의 대칭 2종류
		vvTetromino.push_back({ {0,0},{0,1},{0,2},{1,0} });
		vvTetromino.push_back({ {0,0},{0,1},{1,0},{2,0} });
		// Z, S 모양
		vvTetromino.push_back({ {0,0},{0,1},{1,1},{1,2} });
		vvTetromino.push_back({ {0,0},{0,1},{-1,1},{-1,2} });
		vvTetromino.push_back({ {0,0},{1,0},{1,-1},{2,-1} });
		vvTetromino.push_back({ {0,0},{1,0},{1,1},{2,1} });
	}
}
