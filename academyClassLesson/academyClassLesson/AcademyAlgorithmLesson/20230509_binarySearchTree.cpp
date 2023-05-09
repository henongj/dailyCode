#include "20230509_binarySearchTree.h"

#include<stdio.h>

void C_BST_20230509::printNode(S_NODE* pNode)
{
	if (!pNode)
		return;

	printf("%d ", pNode->m_nData);
	printNode(pNode->m_pLeft);
	printNode(pNode->m_pRight);
}

C_BST_20230509::S_NODE* C_BST_20230509::createNode(int nData)
{
	S_NODE* pNode = new S_NODE{};
	pNode->m_nData = nData;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

void C_BST_20230509::findMaxNode(S_NODE*& pMaxNode, S_NODE*& pMaxNodeParent)
{
	if (!pMaxNode->m_pRight)
		return;

	pMaxNodeParent = pMaxNode;
	pMaxNode = pMaxNode->m_pRight;
	findMaxNode(pMaxNode, pMaxNodeParent);
}

void C_BST_20230509::eraseNode(S_NODE* pNode, S_NODE* pParent)
{
	S_NODE* pNextNode{};

	pNextNode = pNode->m_pLeft;

	if (pNode->m_pRight)
		pNextNode = pNode->m_pRight;

	if (!pParent)
		m_pRoot = pNextNode;
	else if (pParent->m_nData > pNode->m_nData)
		pParent->m_pLeft = pNextNode;
	else if (pParent->m_nData < pNode->m_nData)
		pParent->m_pRight = pNextNode; pParent;
	
	delete pNode;
}

bool C_BST_20230509::add(int nData)
{
	if (!m_pRoot)
	{
		m_pRoot = createNode(nData);
		return true;
	}

	S_NODE* pFind = m_pRoot;
	bool isDupulicate{};

	isDupulicate = false;

	//주의 : 반복문에 break, return 사용 금지
	//단일 포인터로만 작업할 것
	while (!isDupulicate) // 중복이 없다면
	{
		if (pFind->m_nData > nData)
		{
			if (pFind->m_pLeft)
				pFind = pFind->m_pLeft;
			else
				pFind->m_pLeft = createNode(nData);
		}
		else if (pFind->m_nData < nData)
		{
			if (pFind->m_pRight)
				pFind = pFind->m_pRight;
			else
				pFind->m_pRight = createNode(nData);
		}
		else
			isDupulicate = true;
	}

	return !isDupulicate; // 중복이 있다 = 에러, 중복이 없다 = 성공, 중복이 없다면 성공이니 true를 반환.
}

void C_BST_20230509::erase(int nData)
{
	S_NODE* pUp{};
	S_NODE* pFind{};

	pFind = m_pRoot;

	while (pFind && pFind->m_nData != nData)
	{
		pUp = pFind;

		if (pFind->m_nData > nData)
			pFind = pFind->m_pLeft;
		else
			pFind = pFind->m_pRight;
	}

	if (!pFind)
		return;
	
	if (pFind->m_pLeft && pFind->m_pRight)
	{
		S_NODE* pMaxNodeParent{};
		S_NODE* pMaxNode{};

		pMaxNode = pFind->m_pLeft;
		pMaxNodeParent = pFind;

		findMaxNode(pMaxNode, pMaxNodeParent);
		printf("parent : %d max : %d\n", pMaxNodeParent->m_nData, pMaxNode->m_nData);
		//erase()

		pFind->m_nData = pMaxNode->m_nData;

		pFind = pMaxNode;
		pUp = pMaxNodeParent;

		return;

	}

	eraseNode(pFind, pUp);

}

bool C_BST_20230509::find(int nData)
{
	return false;
}

void C_BST_20230509::print(void)
{
	printNode(m_pRoot);
	printf("\n");

}

