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

//https://www.acmicpc.net/problem/1043
//°ÅÁþ¸»
struct node
{
	int m_nId;
	bool isKnowTruth;
	std::vector<node*> m_vFriend;
};
void solution02_acmicpc1043(void);
void dataInput02_acmicpc1043(int& nPeople, int& nParty, int& nPersonNumKnowTruth, std::vector<node>& vPeople, std::vector<int>& vKnowTruth, std::vector<std::vector<int>>& vvParty);
void connectPeopleSameParty_acmicpc1043(std::vector<node>& vPeople, const std::vector<std::vector<int>>& vvParty, std::vector<bool>& vVisited, node* pNodeStart);
int mainSpace02_acmicpc1043(void)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	solution02_acmicpc1043();

	return 0;
}

void solution02_acmicpc1043(void)
{
	int nPeopleNum{};
	int nPartyNum{};
	int nPersonNumKnowTruth{};
	std::vector<node> vPeople{};
	std::vector<std::vector<int>> vvParty{};
	std::vector<int> vKnowTruth{};
	std::vector<bool> vVisited{};
	int nResult{};


	dataInput02_acmicpc1043(nPeopleNum, nPartyNum, nPersonNumKnowTruth, vPeople, vKnowTruth, vvParty);
	vVisited.resize(vPeople.size(), false);
	for (int i = 0; i < vKnowTruth.size(); i++)
	{
		node* pNode = &vPeople[vKnowTruth[i]];
		connectPeopleSameParty_acmicpc1043(vPeople, vvParty, vVisited, pNode);
		for (int i = 0; i < vVisited.size(); i++)
			vVisited[i] = false;
	}

	nResult = 0;
	for (int i = 0; i < vvParty.size(); i++)
	{
		bool isThereTruthPerson = false;
		for (int j = 0; j < vvParty[i].size(); j++)
		{
			if (vPeople[vvParty[i][j]].isKnowTruth)
				isThereTruthPerson = true;
		}
		if (!isThereTruthPerson)
			nResult++;
	}

	std::cout << nResult;
}

void dataInput02_acmicpc1043(int& nPeople, int& nParty, int& nPersonNumKnowTruth, std::vector<node>& vPeople, std::vector<int>& vKnowTruth, std::vector<std::vector<int>>& vvParty)
{
	std::cin >> nPeople;
	std::cin >> nParty;
	std::cin >> nPersonNumKnowTruth;

	vPeople.resize(nPeople + 1);
	vvParty.reserve(nParty);
	vKnowTruth.reserve(nPersonNumKnowTruth);

	for (int i = 0; i < vPeople.size(); i++)
	{
		vPeople[i].m_nId = i;
		vPeople[i].isKnowTruth = false;
		vPeople[i].m_vFriend.resize(nPeople + 1, nullptr);
	}

	for (int i = 0; i < nPersonNumKnowTruth; i++)
	{
		int nPersonKnowTruth{};
		std::cin >> nPersonKnowTruth;
		vKnowTruth.push_back(nPersonKnowTruth);
		vPeople[nPersonKnowTruth].isKnowTruth = true;
	}


	for (int i = 0; i < nParty; i++)
	{
		vvParty.push_back(std::vector<int>{});

		int nPeopleInParty{};
		std::cin >> nPeopleInParty;
		vvParty[i].reserve(nPeopleInParty);

		for (int j = 0; j < nPeopleInParty; j++)
		{
			int nTemp{};
			std::cin >> nTemp;
			vvParty[i].push_back(nTemp);
		}

		for (int j = 0; j < nPeopleInParty; j++)
		{
			int nPerson = vvParty[i][j];

			for (int k = 0; k < vvParty[i].size(); k++)
			{
				vPeople[nPerson].m_vFriend[vvParty[i][k]] = &vPeople[vvParty[i][k]];
			}
		}
	}

}

void connectPeopleSameParty_acmicpc1043(std::vector<node>& vPeople, const std::vector<std::vector<int>>& vvParty, std::vector<bool>& vVisited, node* pNodeStart)
{
	int nNodeId = pNodeStart->m_nId;
	if (vVisited[nNodeId])
		return;

	vVisited[nNodeId] = true;
	vPeople[nNodeId].isKnowTruth = true;

	for (int i = 0; i < pNodeStart->m_vFriend.size(); i++)
	{
		node* pFriend = pNodeStart->m_vFriend[i];
		if (pFriend)
			connectPeopleSameParty_acmicpc1043(vPeople, vvParty, vVisited, pFriend);
	}

}
