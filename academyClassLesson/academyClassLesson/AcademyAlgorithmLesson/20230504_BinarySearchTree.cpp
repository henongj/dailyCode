#include "20230504_BinarySearchTree.h"
#include<stdio.h>

void C_BST_20230504::printNode(S_NODE* pNode)
{
	if (!pNode)
		return;

	printf("%d ", pNode->m_nData);
	printNode(pNode->m_pLeft);
	printNode(pNode->m_pRight);
}

C_BST_20230504::S_NODE* C_BST_20230504::createNode(int nData)
{
	S_NODE* pNode = new S_NODE{};
	pNode->m_nData = nData;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

bool C_BST_20230504::add(int nData)
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

void C_BST_20230504::erase(int nData)
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
		return;
	
	S_NODE* pNextNode{};

	pNextNode = pFind->m_pLeft;
	
	if (pFind->m_pRight)
		pNextNode = pFind->m_pRight;

	if(!pUp)
		m_pRoot = pNextNode;
	else if (pUp->m_nData > pFind->m_nData)
		pUp->m_pLeft = pNextNode;
	else if (pUp->m_nData < pFind->m_nData)
		pUp->m_pRight = pNextNode;

	delete pFind;
}

bool C_BST_20230504::find(int nData)
{
	return false;
}

void C_BST_20230504::print(void)
{
	printNode(m_pRoot);
	printf("\n");

}

