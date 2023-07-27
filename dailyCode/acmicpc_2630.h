#pragma once
//
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
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

//https://www.acmicpc.net/problem/2630
//색종이 만들기
namespace acmicpc_2680 {
	void solution_acmicpc2630(void);
	void inputData_acmicpc2630(std::vector<std::vector<int>>& vvPaper, int& nPaperSize);
	bool isRightPaper(const std::vector<std::vector<int>>& vvPaper, const std::pair<int, int>& pStartPos, const int nPaperSize);
	void checkPaper(std::vector<std::vector<bool>>& vvPaper, const std::pair<int, int>& pStartPos, const int nPaperSize);

	int mainSpace01_acmicpc2680(void)
	{
		//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc2630();

		return 0;
	}

	void solution_acmicpc2630(void)
	{
		std::vector<std::vector<int>> vvPaper{};
		std::vector<std::vector<bool>> vvPaperCheck{};
		int nPaperSize{};
		int nSquareSize{};
		int nWhitePaper{};
		int nBluePaper{};
		int arrColor[2]{};

		inputData_acmicpc2630(vvPaper, nPaperSize);
		nSquareSize = nPaperSize;
		vvPaperCheck.resize(vvPaper.size(), std::vector<bool>(nPaperSize, false));

		while (nSquareSize > 1)
		{
			for (int nRow = 0; nRow + nSquareSize - 1 < nPaperSize; nRow += nSquareSize)
			{
				for (int nColumn = 0; nColumn + nSquareSize - 1 < nPaperSize; nColumn += nSquareSize)
				{
					if (!vvPaperCheck[nRow][nColumn] && isRightPaper(vvPaper, { nRow,nColumn }, nSquareSize))
					{
						checkPaper(vvPaperCheck, { nRow,nColumn }, nSquareSize);
						arrColor[vvPaper[nRow][nColumn]] = arrColor[vvPaper[nRow][nColumn]] + 1;

					}
				}
			}

			nSquareSize /= 2;
		}

		for (int nRow = 0; nRow < nPaperSize; nRow++)
		{
			for (int nCol = 0; nCol < nPaperSize; nCol++)
			{
				if (!vvPaperCheck[nRow][nCol])
				{
					arrColor[vvPaper[nRow][nCol]] = arrColor[vvPaper[nRow][nCol]] + 1;
					vvPaperCheck[nRow][nCol] = true;
				}
			}
		}

		//for (int i = 0; i < nPaperSize; i++)
		//{
		//	for (int j = 0; j < nPaperSize; j++)
		//		std::cout << vvPaperCheck[i][j] << ", ";
		//	std::cout << "\n";
		//}
		std::cout << arrColor[0] << "\n" << arrColor[1] << "\n";
	}

	void inputData_acmicpc2630(std::vector<std::vector<int>>& vvPaper, int& nPaperSize)
	{
		std::cin >> nPaperSize;
		vvPaper.resize(nPaperSize, std::vector<int>(nPaperSize, 0));

		for (int row = 0; row < nPaperSize; row++)
		{
			for (int column = 0; column < nPaperSize; column++)
				std::cin >> vvPaper[row][column];
		}
	}

	bool isRightPaper(const std::vector<std::vector<int>>& vvPaper, const std::pair<int, int>& pStartPos, const int nPaperSize)
	{
		int nStartRow = pStartPos.first;
		int nStartColumn = pStartPos.second;
		int nColorValue = vvPaper[nStartRow][nStartColumn];

		for (int row = nStartRow; row < nStartRow + nPaperSize; row++)
		{
			for (int column = nStartColumn; column < nStartColumn + nPaperSize; column++)
			{
				if (nColorValue != vvPaper[row][column])
					return false;
			}
		}

		return true;
	}

	void checkPaper(std::vector<std::vector<bool>>& vvPaperCheck, const std::pair<int, int>& pStartPos, const int nPaperSize)
	{
		int nStartRow = pStartPos.first;
		int nStartColumn = pStartPos.second;
		int nColorValue = vvPaperCheck[nStartRow][nStartColumn];

		for (int row = nStartRow; row < nStartRow + nPaperSize; row++)
		{
			for (int column = nStartColumn; column < nStartColumn + nPaperSize; column++)
				vvPaperCheck[row][column] = true;
		}
	}

	/*
	8
	1 1 0 0 0 0 1 1
	1 1 0 0 0 0 1 1
	0 0 0 0 1 1 0 0
	0 0 0 0 1 1 0 0
	1 0 0 0 1 1 1 1
	0 1 0 0 1 1 1 1
	0 0 1 1 1 1 1 1
	0 0 1 1 1 1 1 1
	*/
}
