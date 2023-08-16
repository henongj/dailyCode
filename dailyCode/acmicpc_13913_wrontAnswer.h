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

//https://www.acmicpc.net/problem/13913
//숨바꼭질 4
namespace acmicpc_13913_wrontAnswer
{
	using namespace std;

	void solution(void);
	int getMinimumTime(int nStart, std::queue<std::pair<int, int>>& qSearch, int nEnd);
	void inputData(int& nStart, int& nEnd);
	bool isInside(int& nNumber);
	void DFS(int& nStartPoint, int& nEndPoint, int nDepth, int& nMinimumTime, vector<int>& vBuffer, map<int, bool>& mVisited);

	void solution(void)
	{
		int nStart{};
		int nEnd{};
		queue<pair<int, int>> qSearch{};

		inputData(nStart, nEnd);
		int nMinimumTime = getMinimumTime(nStart, qSearch, nEnd);

		cout << nMinimumTime << "\n";

		// vMemo[nEnd]번까지 탐색해서 경로를 출력
		// 방법은 DFS, 깊이가 nMinimumTime인 것중에 nEnd인 것을 출력
		// DFS를 하면서 경로를 저장해놓고, 경로를 출력
		vector<int> vBuffer{};
		int nDepth = 0;
		int nStartPoint = nStart;
		int nEndPoint = nEnd;
		map<int, bool> mVisited;
		DFS(nStartPoint, nEndPoint, nDepth, nMinimumTime, vBuffer, mVisited);

		cout << nStart << " ";

		for (auto& i : vBuffer)
			cout << i << " ";
	}

	int getMinimumTime(int nStart, std::queue<std::pair<int, int>>& qSearch, int nEnd)
	{
		vector<pair<int, int>> vMemo{};
		vMemo.resize(100001);
		int nCount = 0;
		vMemo[nStart].first = nStart;
		vMemo[nStart].second = 0;

		qSearch.push(vMemo[nStart]);

		while (vMemo[nEnd].second == 0)
		{
			pair<int, int> pInfo = qSearch.front();
			qSearch.pop();

			int nPosition = pInfo.first;
			int nTime = pInfo.second;

			int nNextPosition1 = nPosition - 1;
			int nNextPosition2 = nPosition + 1;
			int nNextPosition3 = nPosition * 2;

			if (isInside(nNextPosition1) && vMemo[nNextPosition1].second == 0)
			{
				vMemo[nNextPosition1].first = nNextPosition1;
				vMemo[nNextPosition1].second = nTime + 1;
				qSearch.push(vMemo[nNextPosition1]);
			}
			if (isInside(nNextPosition2) && vMemo[nNextPosition2].second == 0)
			{
				vMemo[nNextPosition2].first = nNextPosition2;
				vMemo[nNextPosition2].second = nTime + 1;
				qSearch.push(vMemo[nNextPosition2]);
			}
			if (isInside(nNextPosition3) && vMemo[nNextPosition3].second == 0)
			{
				vMemo[nNextPosition3].first = nNextPosition3;
				vMemo[nNextPosition3].second = nTime + 1;
				qSearch.push(vMemo[nNextPosition3]);
			}
		}

		return vMemo[nEnd].second;
	}

	void DFS(int& nStartPoint, int& nEndPoint, int nDepth, int& nMinimumTime, vector<int>& vBuffer, map<int, bool>& mVisited)
	{
		if (vBuffer.size() == nMinimumTime)
			return;

		if (mVisited[nStartPoint] == true)
			return;

		int nNextPosition1 = nStartPoint - 1;
		int nNextPosition2 = nStartPoint + 1;
		int nNextPosition3 = nStartPoint * 2;

		if (isInside(nNextPosition1))
		{
			vBuffer.push_back(nNextPosition1);
			DFS(nNextPosition1, nEndPoint, nDepth + 1, nMinimumTime, vBuffer, mVisited);

			if (vBuffer.back() == nEndPoint)
			{
				nDepth--;
				return;
			}

			vBuffer.pop_back();
			nDepth--;
		}

		if (isInside(nNextPosition2))
		{
			vBuffer.push_back(nNextPosition2);
			DFS(nNextPosition2, nEndPoint, nDepth + 1, nMinimumTime, vBuffer, mVisited);

			if (vBuffer.back() == nEndPoint)
			{
				nDepth--;
				return;
			}

			vBuffer.pop_back();
			nDepth--;
		}

		if (isInside(nNextPosition3))
		{
			vBuffer.push_back(nNextPosition3);
			DFS(nNextPosition3, nEndPoint, nDepth + 1, nMinimumTime, vBuffer, mVisited);

			if (vBuffer.back() == nEndPoint)
			{
				nDepth--;
				return;
			}

			vBuffer.pop_back();
			nDepth--;
		}

	}
	void inputData(int& nStart, int& nEnd)
	{
		cin >> nStart >> nEnd;
	}
	bool isInside(int& nNumber)
	{
		if (0 <= nNumber && nNumber <= 100000)
			return true;
		return false;
	}
}
