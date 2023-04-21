#include "20230421_linkedList_List.h"
#include<stdio.h>
C_linked_list_2023_04_21::C_linked_list_2023_04_21() :
	m_cBeginDummy{},
	m_cEndDummy{},
	m_pBegin{},
	m_pEnd{}
{
	m_pBegin = &m_cBeginDummy;
	m_pEnd = &m_cEndDummy;

	linkNode(m_pBegin, m_pEnd);
}

C_node_2023_04_21* C_linked_list_2023_04_21::createNode(int nData)
{
	C_node_2023_04_21* pNewNode = new C_node_2023_04_21{};
	pNewNode->m_nData = nData;
	return pNewNode;
}

void C_linked_list_2023_04_21::linkNode(C_node_2023_04_21* pPrev, C_node_2023_04_21* pNext)
{
	pPrev->m_pNextNode = pNext;
	pNext->m_pPrevNode = pPrev;
}

void C_linked_list_2023_04_21::insertNode(C_node_2023_04_21* pPrev, C_node_2023_04_21* pNewNode, C_node_2023_04_21* pNext)
{
	linkNode(pPrev, pNewNode);
	linkNode(pNewNode, pNext);
}

C_node_2023_04_21* C_linked_list_2023_04_21::getBegin()
{
	return m_pBegin->m_pNextNode;
}

C_node_2023_04_21* C_linked_list_2023_04_21::getEnd()
{
	return m_pEnd;
}

void C_linked_list_2023_04_21::pushBack(int nData)
{
	C_node_2023_04_21* pNewNode = createNode(nData);
	insertNode(m_pEnd->m_pPrevNode, pNewNode, m_pEnd);
}

void C_linked_list_2023_04_21::pushFront(int nData)
{
	C_node_2023_04_21* pNewNode = createNode(nData);
	insertNode(m_pBegin, pNewNode, m_pBegin->m_pNextNode);
}

void C_linked_list_2023_04_21::deleteNode(C_node_2023_04_21* pNode)
{
	linkNode(pNode->m_pPrevNode, pNode->m_pNextNode);
	delete pNode;
}

void C_linked_list_2023_04_21::removeNode(C_node_2023_04_21* pBegin, C_node_2023_04_21* pEnd, int nData)
{
	C_node_2023_04_21* pCurrent = pBegin;
	while (pCurrent != pEnd)
	{
		if (pCurrent->m_nData == nData)
		{
			C_node_2023_04_21* pDeleteNode{};
			pDeleteNode = pCurrent;
			pCurrent = pCurrent->m_pNextNode;
			deleteNode(pDeleteNode);
		}
		else
			pCurrent = pCurrent->m_pNextNode;
	}
}

void C_linked_list_2023_04_21::printList()
{
	C_node_2023_04_21* pCurrent = m_pBegin->m_pNextNode;
	while (pCurrent != m_pEnd)
	{
		printf("%d ", pCurrent->m_nData);
		pCurrent = pCurrent->m_pNextNode;
	}
	puts("");
}

