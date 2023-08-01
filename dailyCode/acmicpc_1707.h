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
namespace acmicpc_1707{
	void solution_acmicpc1707(void);
	void inputData_acmicpc1707(std::vector<std::vector<int>>& vvGraph, int& nNumOfVertex, int& nNumOfEdge);
	bool isBipartiteGraph(const std::vector<std::vector<int>>& vvGraph, int nNumOfVertex);

	int mainSpace01(void)
	{
		solution_acmicpc1707();

		return 0;
	}

	void solution_acmicpc1707(void)
	{
		using namespace std;

		int nTestCase{};
		int nNumOfVertex{};
		int nNumOfEdge{};

		cin >> nTestCase;
		for (int i = 0; i < nTestCase; i++)
		{
			vector<vector<int>> vvGraph{};
			inputData_acmicpc1707(vvGraph, nNumOfVertex, nNumOfEdge);
			if (isBipartiteGraph(vvGraph, nNumOfVertex))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	void inputData_acmicpc1707(std::vector<std::vector<int>>& vvGraph, int& nNumOfVertex, int& nNumOfEdge)
	{
		using namespace std;
		int nVertex1{};
		int nVertex2{};
		cin >> nNumOfVertex;
		cin >> nNumOfEdge;
		vvGraph.resize(nNumOfVertex, vector<int>{});
		for (int i = 0; i < vvGraph.size(); i++)
			vvGraph.reserve(20);

		for (int i = 0; i < nNumOfEdge; ++i)
		{
			cin >> nVertex1;
			cin >> nVertex2;
			vvGraph[nVertex1 - 1].push_back(nVertex2 - 1);
			vvGraph[nVertex2 - 1].push_back(nVertex1 - 1);
		}
	}

	bool isBipartiteGraph(const std::vector<std::vector<int>>& vvGraph, int nNumOfVertex)
	{
		using namespace std;

		queue<int> qVertex{};
		vector<bool> vVisited{};
		vector<int> vColor{};

		vVisited.resize(nNumOfVertex, false);
		vColor.resize(nNumOfVertex, 0);

		for (int i = 0; i < nNumOfVertex; ++i)
		{
			if (vVisited[i])
				continue;

			qVertex.push(i);
			vVisited[i] = true;
			vColor[i] = 1;

			while (!qVertex.empty())
			{
				int nCurVertex = qVertex.front();
				qVertex.pop();

				for (int j = 0; j < vvGraph[nCurVertex].size(); ++j)
				{
					int nNextVertex = vvGraph[nCurVertex][j];
					if (vVisited[nNextVertex])
					{
						if (vColor[nCurVertex] == vColor[nNextVertex])
							return false;
					}
					else
					{
						qVertex.push(nNextVertex);
						vVisited[nNextVertex] = true;
						vColor[nNextVertex] = vColor[nCurVertex] * -1;
					}
				}
			}
		}

		return true;

	}
}

/*
11
3 1
2 3
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
3 2
2 1
3 2
4 4
2 1
3 2
4 3
4 1
5 2
1 5
1 2
5 2
1 2
2 5
4 3
1 2
4 3
2 3
4 4
2 3
1 4
3 4
1 2
3 3
1 2
2 3
3 1
2 1
1 2

YES
YES
NO
YES
YES
YES
YES
YES
YES
NO
YES
*/