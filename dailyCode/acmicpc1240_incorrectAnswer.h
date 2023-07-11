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
struct node
{
	int m_nId;
	std::unordered_map<int, int> m_mapConnected; // id , distance
};
void solution_acmicpc1240(void);
void dataInput_acmicpc1240(int& nNumOfNodes, int& nNumOfQueries, std::vector<std::vector<int>>& vDistances, std::vector<std::pair<int, int>>& vQueries);
void makeNodes_acmicpc1240(const std::vector<std::vector<int>>& vDistances, std::unordered_map<int, node>& mapNodes);
int getDistance_acmicpc1240(const std::unordered_map<int, node>& mapNodes, const std::pair<int, int>& vQuery, std::vector<bool>& vVisited, const node* pNode, int nDistance);

int mainSapce_acmicpc1240(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution_acmicpc1240();

	return 0;
}

void solution_acmicpc1240(void)
{
	int nNumOfNodes{};
	int nNumOfQueries{};
	std::vector<std::vector<int>> vDistances{};
	std::vector<std::pair<int, int>> vQueries{};
	std::unordered_map<int, node> mapNodes{};
	std::vector<bool> vVisited{};

	dataInput_acmicpc1240(nNumOfNodes, nNumOfQueries, vDistances, vQueries);
	makeNodes_acmicpc1240(vDistances, mapNodes);
	vVisited.resize(mapNodes.size() + 1, false);

	for (int i = 0; i < vQueries.size(); i++)
	{
		vVisited.clear();
		vVisited.resize(mapNodes.size() + 1, false);
		int nDistance = 0;
		const node* pNode = &mapNodes.find(vQueries[i].first)->second;

		nDistance = getDistance(mapNodes, vQueries[i], vVisited, pNode, nDistance);

		std::cout << nDistance << "\n";
	}


}

void dataInput_acmicpc1240(int& nNumOfNodes, int& nNumOfQueries, std::vector<std::vector<int>>& vDistances, std::vector<std::pair<int, int>>& vQueries)
{
	int nTemp1{};
	int nTemp2{};
	int nTemp3{};

	std::cin >> nNumOfNodes;
	std::cin >> nNumOfQueries;

	vDistances.reserve(nNumOfNodes - 1);
	vQueries.reserve(nNumOfQueries);

	for (int i = 0; i < nNumOfNodes - 1; i++)
	{
		std::cin >> nTemp1 >> nTemp2 >> nTemp3;
		std::vector<int> vDistance{};
		vDistance.reserve(3);
		vDistance.push_back(nTemp1);
		vDistance.push_back(nTemp2);
		vDistance.push_back(nTemp3);

		vDistances.push_back(vDistance);
	}

	for (int i = 0; i < nNumOfQueries; i++)
	{
		std::cin >> nTemp1 >> nTemp2;
		std::pair<int, int> pQuery{};
		pQuery.first = nTemp1;
		pQuery.second = nTemp2;

		vQueries.push_back(pQuery);
	}
}
void makeNodes_acmicpc1240(const std::vector<std::vector<int>>& vDistances, std::unordered_map<int, node>& mapNodes)
{
	int nNodeId{};
	std::unordered_map<int, node>::iterator mapIter{};

	nNodeId = 1;
	size_t nNodeSize = vDistances.size() + 1;
	for (size_t i = 0; i < nNodeSize; i++)
	{
		node ndTemp{};
		ndTemp.m_nId = nNodeId;
		mapNodes.insert({ nNodeId, ndTemp });
		nNodeId++;
	}
	for (size_t i = 0; i < vDistances.size(); i++)
	{
		int nStart = vDistances[i][0];
		int nEnd = vDistances[i][1];
		int nDistance = vDistances[i][2];

		mapIter = mapNodes.find(nStart);
		mapIter->second.m_mapConnected.insert({ nEnd ,nDistance });
		mapIter = mapNodes.find(nEnd);
		mapIter->second.m_mapConnected.insert({ nStart ,nDistance });
	}

}

int getDistance(const std::unordered_map<int, node>& mapNodes, const std::pair<int, int>& vQuery, std::vector<bool>& vVisited, const node* pNode, int nDistance)
{
	const std::unordered_map<int, node>::const_iterator nodeIter = mapNodes.find(pNode->m_nId);

	vVisited[pNode->m_nId] = true;

	std::unordered_map<int, int>::const_iterator distanceIter = nodeIter->second.m_mapConnected.find(vQuery.second);

	if (distanceIter != nodeIter->second.m_mapConnected.end())
	{
		//destination
		nDistance += vQuery.second;
		return nDistance;
	}
	else
	{
		//keep find
		distanceIter = nodeIter->second.m_mapConnected.begin();
		while (distanceIter != nodeIter->second.m_mapConnected.end())
		{
			const node* pNext = &mapNodes.find(distanceIter->first)->second;
			if (vVisited[pNext->m_nId] != true)
			{
				nDistance = nDistance + distanceIter->second;
				nDistance = getDistance(mapNodes, vQuery, vVisited, pNext, nDistance);
			}
			distanceIter++;
		}
	}

	return nDistance;
}



