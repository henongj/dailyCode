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

//https://www.acmicpc.net/problem/1707
//이분 그래프
namespace acmicpc_1707_wrongAnswer
{
	void solution_acmicpc1707(void);
	void inputData_acmicpc1707(std::vector<std::vector<int>>& vvGraph, int& nNumOfVertex, int& nNumOfEdge);
	bool isBipartiteGraph(const std::vector<std::vector<int>>& vvGraph, int nNumOfVertex);

	int mainSpace01_acmicpc1707(void)
	{
		//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		solution_acmicpc1707();

		return 0;
	}

	void solution_acmicpc1707(void)
	{
		using namespace std;

		int nTestCase{};
		int nNumOfVertex{};
		int nNumOfEdge{};
		vector<vector<int>> vvGraph{};

		cin >> nTestCase;
		for (int i = 0; i < nTestCase; ++i)
		{
			inputData_acmicpc1707(vvGraph, nNumOfVertex, nNumOfEdge);
			if (isBipartiteGraph(vvGraph, nNumOfVertex))
				cout << "YES\n" << endl;
			else
				cout << "NO\n" << endl;
		}
	}

	void inputData_acmicpc1707(std::vector<std::vector<int>>& vvGraph, int& nNumOfVertex, int& nNumOfEdge)
	{
		using namespace std;

		cin >> nNumOfVertex >> nNumOfEdge;
		vvGraph.resize(nNumOfVertex);
		for (int i = 0; i < nNumOfEdge; ++i)
		{
			int nVertex1{};
			int nVertex2{};
			cin >> nVertex1 >> nVertex2;
			vvGraph[nVertex1 - 1].push_back(nVertex2 - 1);
			vvGraph[nVertex2 - 1].push_back(nVertex1 - 1);
		}
	}

	bool isBipartiteGraph(const std::vector<std::vector<int>>& vvGraph, int nNumOfVertex)
	{
		using namespace std;

		queue<int> qVertex{};
		vector<bool> vVisited{};
		vector<bool> vColor{};

		vVisited.resize(nNumOfVertex);
		vColor.resize(nNumOfVertex);

		for (int i = 0; i < nNumOfVertex; ++i)
		{
			if (vVisited[i])
				continue;

			qVertex.push(i);
			vVisited[i] = true;

			while (!qVertex.empty())
			{
				int nVertex = qVertex.front();
				qVertex.pop();

				for (int j = 0; j < vvGraph[nVertex].size(); ++j)
				{
					int nNextVertex = vvGraph[nVertex][j];
					if (vVisited[nNextVertex])
					{
						if (vColor[nVertex] == vColor[nNextVertex])
							return false;
					}
					else
					{
						qVertex.push(nNextVertex);
						vVisited[nNextVertex] = true;
						vColor[nNextVertex] = (!vColor[nVertex]);
					}
				}
			}
		}
		return true;
	}

}