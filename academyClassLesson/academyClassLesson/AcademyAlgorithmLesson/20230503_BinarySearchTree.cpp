#include<stdio.h>
#include "20230503_BinarySearchTree.h"

void C_BST_20230503::printNode(S_NODE* pNode)
{
	if (!pNode)
		return;
    
	printf("%d ", pNode->m_nData);
	printNode(pNode->m_pLeft);
	printNode(pNode->m_pRight);
}

C_BST_20230503::S_NODE* C_BST_20230503::createNode(int nData)
{
	S_NODE* pNode = new S_NODE{};
	pNode->m_nData = nData;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

bool C_BST_20230503::add(int nData)
{
	if(!m_pRoot)
	{
		m_pRoot = createNode(nData);
		return true;
	}

	S_NODE* pFind = m_pRoot;
	
	//주의 : 반복문에 break, return 사용 금지
	//단일 포인터로만 작업할 것
	while (true)
	{
		if (pFind->m_nData > nData)
		{
			if (pFind->m_pLeft)
				pFind = pFind->m_pLeft;
			else
			{
				pFind = createNode(nData);
				return true;
			}

		}
		else if (pFind->m_nData < nData)
		{
			if (pFind->m_pRight)
				pFind = pFind->m_pRight;
			else
			{
				pFind = createNode(nData);
				return true;
			}
		}
		else
			return false;
	}
	
    return true;
}

void C_BST_20230503::erase(int nData)
{
}

bool C_BST_20230503::find(int nData)
{
    return false;
}

void C_BST_20230503::print(void)
{
	printNode(m_pRoot);
	printf("\n");
	
}
