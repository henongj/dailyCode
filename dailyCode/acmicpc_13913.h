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
//¼û¹Ù²ÀÁú 4
namespace acmicpc_13913
{
	using namespace std;

	void solution(void);
	void inputData(int& nStart, int& nEnd);
	bool isInside(int& nNumber);
	void BFS(int& nStart, int& nEnd, vector<pair<int, int>>& vPath, vector<bool>& vVisited, bool& flag);
	void getPath(int& nStart, int& nEnd, vector<pair<int, int>>& vPath, vector<int>& vPathBuffer, int& nPathCount);

	void solution(void)
	{
		int nStart{};
		int nEnd{};
		vector<pair<int, int>> vPath{};
		vector<bool> vVisited{};

		inputData(nStart, nEnd);
		vVisited.resize(100001, false);
		vPath.resize(100001);

		bool flag = false;

		BFS(nStart, nEnd, vPath, vVisited, flag);

		int nPathCount = 0;
		vector<int> vPathBuffer{};
		vPathBuffer.reserve(50);

		getPath(nStart, nEnd, vPath, vPathBuffer, nPathCount);

		vPathBuffer.push_back(nStart);

		cout << nPathCount << "\n";

		for (auto iter = vPathBuffer.rbegin(); iter != vPathBuffer.rend(); iter++)
			cout << *iter << " ";


	}
	void inputData(int& nStart, int& nEnd)
	{
		cin >> nStart >> nEnd;
	}
	bool isInside(int& nNumber)
	{
		if (nNumber >= 0 && nNumber <= 100000)
			return true;
		return false;
	}
	void BFS(int& nStart, int& nEnd, vector<pair<int, int>>& vPath, vector<bool>& vVisited, bool& flag)
	{
		int nPathChoice[4] = { 0, 1, -1, 2 };
		vPath[nStart] = { nStart, nPathChoice[0] };
		vVisited[nStart] = true;

		queue<pair<int, int>> qSearch{};
		qSearch.push(vPath[nStart]);

		while (!flag)
		{
			pair<int, int> pInfo = qSearch.front();
			int nPosition = pInfo.first;
			int nPath = pInfo.second;

			qSearch.pop();

			int nNextPosition[3] = { nPosition - 1, nPosition + 1, nPosition * 2 };
			for (int i = 0; i < 3; i++)
			{
				if (isInside(nNextPosition[i]) && vVisited[nNextPosition[i]] == false)
				{
					vPath[nNextPosition[i]].first = nNextPosition[i];
					vPath[nNextPosition[i]].second = nPathChoice[i + 1];

					vVisited[nNextPosition[i]] = true;
					qSearch.push(vPath[nNextPosition[i]]);

					if (vVisited[nEnd])
						flag = true;
				}

			}
		}

	}
	void getPath(int& nStart, int& nEnd, vector<pair<int, int>>& vPath, vector<int>& vPathBuffer, int& nPathCount)
	{
		int nPathChoice[4] = { 0, 1, -1, 2 }; // 0 = destination, 1 = -1, 2 = +1 , 3 = /2
		int nPath = vPath[nEnd].second;
		int nPosition = vPath[nEnd].first;

		while (nPath != 0)
		{
			nPathCount++;
			vPathBuffer.push_back(nPosition);
			switch (nPath)
			{
			case 0:
				break;
			case 1:
				nPosition++;
				nPath = vPath[nPosition].second;
				break;
			case -1:
				nPosition--;
				nPath = vPath[nPosition].second;
				break;
			case 2:
				nPosition /= 2;
				nPath = vPath[nPosition].second;
				break;
			}
		}
	}
}

