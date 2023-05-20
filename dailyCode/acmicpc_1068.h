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

//https://www.acmicpc.net/problem/1068
void dataInput_acmicpc1068(int& nNodeNum, std::vector<int>& vNodeParent, int& nNodeToDelete);

void isNodeToDelete(const int nParentID, const int nNodeID, const std::vector<int*>& vNodeParent, bool& bResult);
void isLeafNode(const std::vector<int*>& vNodeParent, std::vector<bool>& vIsLeafNode);
void solution_acmicpc1068(void);


void solution_acmicpc1068(void)
{
	int nNodeNum{};
	std::vector<int> vData{};
	std::vector<int*> vNodeParent{};
	std::vector<bool> vIsLeafNode{};
	int nNodeToDelete{};
	bool isToDeleteNode{};
	int nCount{};

	dataInput_acmicpc1068(nNodeNum, vData, nNodeToDelete);
	vNodeParent.resize(nNodeNum);
	vIsLeafNode.resize(nNodeNum);
	for (int i = 0; i < nNodeNum; i++)
		vNodeParent[i] = &vData[i];

	for (int i = 0; i < nNodeNum; i++)
	{
		bool isToDelete{};
		isNodeToDelete(nNodeToDelete, i, vNodeParent, isToDelete);

		if (isToDelete)
			vNodeParent[i] = nullptr;

		//std::cout << isToDelete << ", ";
	}
	//std::cout << "\n";

	isLeafNode(vNodeParent, vIsLeafNode);
	//for (int i = 0; i < nNodeNum; i++)
	//{
	//	std::cout << vIsLeafNode[i] << ", ";
	//}
	//std::cout << "\n";

	nCount = 0;
	for (int i = 0; i < nNodeNum; i++)
	{
		if (vNodeParent[i] && vIsLeafNode[i])
			nCount++;
	}

	std::cout << nCount;
}
void dataInput_acmicpc1068(int& nNodeNum, std::vector<int>& vNodeParent, int& nNodeToDelete)
{
	std::cin >> nNodeNum;

	vNodeParent.resize(nNodeNum);
	for (int i = 0; i < nNodeNum; ++i)
		std::cin >> vNodeParent[i];

	std::cin >> nNodeToDelete;
}


void isNodeToDelete(const int nParentID, const int nNodeID, const std::vector<int*>& vNodeParent, bool& bResult)
{
	if (!vNodeParent[nNodeID] || nParentID == nNodeID)
	{
		bResult = true;
		return;
	}

	if (*vNodeParent[nNodeID] == -1)
	{
		bResult = false;
		return;
	}

	isNodeToDelete(nParentID, *vNodeParent[nNodeID], vNodeParent, bResult);
}

void isLeafNode(const std::vector<int*>& vNodeParent, std::vector<bool>& vIsLeafNode)
{
	int nNodeCount{};
	size_t nSize = vNodeParent.size();
	nNodeCount = (int)nSize;
	for (int i = 0; i < nSize; i++)
	{
		vIsLeafNode[i] = true;
		if (!vNodeParent[i])
			nNodeCount--;
	}

	//std::cout << "nNodeCount : " << nNodeCount << "\n";
	for (int i = 0; i < nSize; i++)
	{
		if (vNodeParent[i])
		{
			if (*vNodeParent[i] == -1)
			{
				if (nNodeCount != 1)
					vIsLeafNode[i] = false;
			}
			else
				vIsLeafNode[*vNodeParent[i]] = false;
		}
		else
			vIsLeafNode[i] = false;
	}
}

/*
6
1 2 3 4 -1 4
5
*/