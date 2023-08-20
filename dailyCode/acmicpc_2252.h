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

//https://www.acmicpc.net/problem/2252
//줄 세우기
namespace acmicpc_2252
{
	using namespace std;

	void solution(void);

	void inputData(int& nPerson, int& nCompare, vector<vector<int>>& vCompare);
	void lineUpHegith(int nPerson, int nCompare, vector<vector<int>>& vCompare, vector<int>& vHeight);

	void solution(void)
	{
		int nPerson{};
		int nCompare{};
		vector<vector<int>> vCompare{};
		vector<int> vHeight{};

		inputData(nPerson, nCompare, vCompare);
		lineUpHegith(nPerson, nCompare, vCompare, vHeight);

		//print
		for (int i = 0; i < nPerson; ++i)
		{
			cout << vHeight[i] << " ";
		}

	}

	void inputData(int& nPerson, int& nCompare, vector<vector<int>>& vCompare)
	{
		cin >> nPerson >> nCompare;
		vCompare.resize(nCompare, vector<int>(2, 0));
		for (int i = 0; i < nCompare; ++i)
		{
			cin >> vCompare[i][0] >> vCompare[i][1];
		}
	}

	void lineUpHegith(int nPerson, int nCompare, vector<vector<int>>& vCompare, vector<int>& vHeight)
	{
		// 위상정렬
		vector<int> vInDegree(nPerson + 1, 0);
		vector<vector<int>> vAdjacent(nPerson + 1, vector<int>{});
		for (int i = 0; i < nCompare; i++)
		{
			vAdjacent[vCompare[i][0]].push_back(vCompare[i][1]);
			vInDegree[vCompare[i][1]]++;
		}

		queue<int> q{};
		for (int i = 1; i <= nPerson; i++)
		{
			if (vInDegree[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int nCur = q.front();
			q.pop();
			vHeight.push_back(nCur);

			for (int i = 0; i < vAdjacent[nCur].size(); ++i)
			{
				int nNext = vAdjacent[nCur][i];
				vInDegree[nNext]--;
				if (vInDegree[nNext] == 0)
					q.push(nNext);
			}
		}
	}
}