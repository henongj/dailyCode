#pragma once
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


//https://www.acmicpc.net/problem/1240
//노드사이의 거리
struct node_acmicpc1240
{
	int m_nId;
	std::vector<std::pair<int,int>> vConnected;
};
void solution2_acmicpc1240(void);
void dataInput2_acmicpc1240(int& nNodeSize, int& nQuerySize, std::vector<node_acmicpc1240*>& vNodes, std::vector<std::pair<int,int>>& vQuery);
void getDistanc_acmicpc1240(const std::vector<node_acmicpc1240*>& vNodes, const std::pair<int, int>& pairQuery, std::vector<bool>& vVisited, node_acmicpc1240* pNodeVisit, int& nDistance, int& nResult);
int mainSapce02_acmicpc1240(void)
{
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	solution2_acmicpc1240();

	return 0;
}

void solution2_acmicpc1240(void)
{
	int nNodeSize{};
	int nQuerySize{};
	std::vector<node_acmicpc1240*> vNodes{};
	std::vector<std::pair<int, int>> vQuery{};
	std::vector<bool> vVisited{};

	dataInput2_acmicpc1240(nNodeSize, nQuerySize, vNodes, vQuery);
	vVisited.resize(vNodes.size(), false);

	for (int i = 0; i < nQuerySize; i++)
	{
		int nResult{};
		int nDistance{};
		
		for (int i = 0; i < vVisited.size(); i++)
			vVisited[i] = false;
		nResult = 0;
		nDistance = 0;

		getDistanc_acmicpc1240(vNodes, vQuery[i], vVisited, vNodes[vQuery[i].first], nDistance, nResult);

		std::cout << nResult << "\n";
	}



	for (int i = 0; i < vNodes.size(); i++)
	{
		delete vNodes[i];
		vNodes[i] = nullptr;
	}
}

void dataInput2_acmicpc1240(int& nNodeSize, int& nQuerySize, std::vector<node_acmicpc1240*>& vNodes, std::vector<std::pair<int, int>>& vQuery)
{
	int nIdCounter = 0;
	std::cin >> nNodeSize;
	std::cin >> nQuerySize;
	
	vNodes.reserve(nNodeSize + 1);
	vQuery.reserve(nQuerySize);

	for (int i = 0; i < nNodeSize + 1; i++)
	{
		node_acmicpc1240* pNode{};
		pNode = new node_acmicpc1240{};
		pNode->m_nId = nIdCounter;
		nIdCounter++;

		vNodes.push_back(pNode);
	}

	for (int i = 0; i < nNodeSize - 1; i++)
	{
		int nIdNode1{};
		int nIdNode2{};
		int nDistance{};

		std::cin >> nIdNode1;
		std::cin >> nIdNode2;
		std::cin >> nDistance;

		vNodes[nIdNode1]->vConnected.push_back({ nIdNode2, nDistance });
		vNodes[nIdNode2]->vConnected.push_back({ nIdNode1, nDistance });

	}

	for (int i = 0; i < nQuerySize ; i++)
	{
		int nStart{};
		int nDestination{};

		std::cin >> nStart;
		std::cin >> nDestination;

		vQuery.push_back({ nStart,nDestination });
	}
}

void getDistanc_acmicpc1240(const std::vector<node_acmicpc1240*>& vNodes, const std::pair<int, int>& pairQuery, std::vector<bool>& vVisited, node_acmicpc1240* pNodeVisit, int& nDistance, int& nResult)
{
	if (vVisited[pNodeVisit->m_nId])
		return;

	vVisited[pNodeVisit->m_nId] = true;

	if (pNodeVisit->m_nId == pairQuery.second)
	{
		nResult = nDistance;
		return;
	}

	for (int i = 0; i < pNodeVisit->vConnected.size(); i++)
	{
		nDistance += pNodeVisit->vConnected[i].second;
		getDistanc_acmicpc1240(vNodes, pairQuery, vVisited, vNodes[pNodeVisit->vConnected[i].first], nDistance, nResult);
		nDistance -= pNodeVisit->vConnected[i].second;
	}
}
