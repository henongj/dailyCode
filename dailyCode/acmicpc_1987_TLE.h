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

//https://www.acmicpc.net/problem/1753
//최단경로
namespace acmicpc_1753_TLE
{
	struct edge
	{
		int nVertexNumber{};
		std::vector<std::pair<int, int>> vWeight{};
	};

	void solution(void);
	void inputData(int& nVertex, int& nEdge, int& startVertex, std::vector<edge>& vEdge);
	void BFS(int nStartVertex, std::vector<edge>& vEdge, std::vector<long long>& vDistance);

	void solution(void)
	{
		int nVertex{};
		int nEdge{};
		int nStartVertex{};
		std::vector<edge> vEdge{};
		std::vector<long long> vDistance{};
		size_t szEdgeSize{};
		long long llMaxDistance{};

		inputData(nVertex, nEdge, nStartVertex, vEdge);
		szEdgeSize = vEdge.size();
		llMaxDistance = 6000000001;
		vDistance.resize(szEdgeSize, llMaxDistance);

		//for (size_t i = 1; i < szEdgeSize; i++)
		//{
		//	//print
		//	std::cout << vEdge[i].nVertexNumber << " : ";
		//	for (size_t j = 0; j < vEdge[i].vWeight.size(); j++)
		//		std::cout << "(" << vEdge[i].vWeight[j].first << ", " << vEdge[i].vWeight[j].second << ") ";
		//	std::cout << std::endl;
		//}
		BFS(nStartVertex, vEdge, vDistance);

		for (size_t i = 1; i < szEdgeSize; i++)
		{
			if (vDistance[i] == llMaxDistance)
				std::cout << "INF" << std::endl;
			else
				std::cout << vDistance[i] << std::endl;
		}
	}
	void inputData(int& nVertex, int& nEdge, int& nStartVertex, std::vector<edge>& vEdge)
	{
		std::cin >> nVertex;
		std::cin >> nEdge;
		std::cin >> nStartVertex;

		int nStart{};
		int nEnd{};
		int nWeight{};

		vEdge.resize(nEdge);
		for (int i = 0; i < nEdge; i++)
		{
			std::cin >> nStart;
			std::cin >> nEnd;
			std::cin >> nWeight;

			vEdge[nStart].vWeight.push_back({ nEnd, nWeight });
		}
		for (int i = 1; i < nEdge; i++)
			vEdge[i].nVertexNumber = i;
	}

	void BFS(int nStartVertex, std::vector<edge>& vEdge, std::vector<long long>& vDistance)
	{
		std::queue<int> qVertex{};
		int nCurrentVertex{};
		int nNextVertex{};
		int nWeight{};
		long long nDistance{};

		qVertex.push(nStartVertex);
		vDistance[nStartVertex] = 0;

		while (!qVertex.empty())
		{
			nCurrentVertex = qVertex.front();
			qVertex.pop();

			for (size_t i = 0; i < vEdge[nCurrentVertex].vWeight.size(); i++)
			{
				nNextVertex = vEdge[nCurrentVertex].vWeight[i].first;
				nWeight = vEdge[nCurrentVertex].vWeight[i].second;
				nDistance = vDistance[nCurrentVertex] + (long long)nWeight;

				if (vDistance[nNextVertex] > nDistance)
				{
					vDistance[nNextVertex] = nDistance;
					qVertex.push(nNextVertex);
				}
			}
		}
	}

}

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



	acmicpc_1753::solution();

	return 0;
}
