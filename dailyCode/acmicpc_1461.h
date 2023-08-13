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

using namespace std;

//https://www.acmicpc.net/problem/1461
//도서관
namespace acmicpc_1461
{
	using namespace std;

	void solution(void);
	void printData(std::vector<int>& vBookPlacePosivite, std::vector<int>& vBookPlaceNegative);
	void inputData(int& nBooks, int& nMaxBookHave, vector<int>& vBookPlacePositive, vector<int>& vBookPlaceNegative);
	void placeBook(int& nBookCount, int& nMaxBookHave, int& nStep, vector<int>& vBookPlace, int nBooks);

	void solution(void)
	{
		int nBooks{};
		int nMaxBookHave{};
		vector<int> vBookPlacePosivite{};
		vector<int> vBookPlaceNegative{};
		int nBookCount{};
		int nStep{};
		vector<int>* pFirst{};
		vector<int>* pSecond{};


		inputData(nBooks, nMaxBookHave, vBookPlacePosivite, vBookPlaceNegative);
		nBookCount = 0;

		sort(vBookPlacePosivite.begin(), vBookPlacePosivite.end());
		sort(vBookPlaceNegative.begin(), vBookPlaceNegative.end());

		//printData(vBookPlacePosivite, vBookPlaceNegative);
		//먼저 가야할 곳을 정한다.
		{
			int nMaxPositive{};
			int nMaxNegative{};
			if (vBookPlacePosivite.size() != 0)
				nMaxPositive = vBookPlacePosivite.back();
			if (vBookPlaceNegative.size() != 0)
				nMaxNegative = vBookPlaceNegative.back();

			if (nMaxPositive > nMaxNegative)
			{
				pFirst = &vBookPlaceNegative;
				pSecond = &vBookPlacePosivite;
			}
			else
			{
				pFirst = &vBookPlacePosivite;
				pSecond = &vBookPlaceNegative;
			}
		}

		// 반납
		while (nBookCount < nBooks)
		{
			placeBook(nBookCount, nMaxBookHave, nStep, *pFirst, nBooks);

			if (nBookCount >= nBooks)
				break;
			placeBook(nBookCount, nMaxBookHave, nStep, *pSecond, nBooks);
			nStep -= pSecond->back();
		}

		cout << nStep << endl;

	}

	void printData(std::vector<int>& vBookPlacePosivite, std::vector<int>& vBookPlaceNegative)
	{
		//print
		for (auto& it : vBookPlacePosivite)
			cout << it << " ";
		cout << endl;
		for (auto& it : vBookPlaceNegative)
			cout << it << " ";
		cout << endl;
	}

	void inputData(int& nBooks, int& nMaxBookHave, vector<int>& vBookPlacePositive, vector<int>& vBookPlaceNegative)
	{
		cin >> nBooks;
		cin >> nMaxBookHave;

		vBookPlaceNegative.reserve(nBooks);
		vBookPlacePositive.reserve(nBooks);

		for (int i = 0; i < nBooks; i++)
		{
			int nBookPosition{};
			cin >> nBookPosition;

			if (nBookPosition < 0)
				vBookPlaceNegative.push_back((int)-1 * nBookPosition);
			else
				vBookPlacePositive.push_back(nBookPosition);
		}
	}

	void placeBook(int& nBookCount, int& nMaxBookHave, int& nStep, vector<int>& vBookPlace, int nBooks)
	{
		int nBookSize = vBookPlace.size(); // 목표 책의 개수
		int nBookPlaced = 0; // 반납 
		int nBookIndex = nBookSize - 1; // 꺼낼 책 인덱스

		while (nBookPlaced < nBookSize)
		{
			int nHaveBook = 0; // 가지고 있는 책의 개수
			int nStepToGo{};
			while (nHaveBook < nMaxBookHave && nHaveBook + nBookPlaced < nBookSize) // 가진 책 + 반납 책 <= 책의 개수
			{
				nStepToGo = max(vBookPlace[nBookIndex], nStepToGo);
				nBookIndex--;
				nHaveBook++;
			}

			nBookPlaced += nHaveBook;
			nBookCount += nHaveBook; // 반납된 전체 책의 개수
			nStep += nStepToGo; // 전체 이동 거리

			nStep += nStepToGo; // 돌아오는 거리
			nHaveBook = 0;
			nStepToGo = 0;
		}
	}




}