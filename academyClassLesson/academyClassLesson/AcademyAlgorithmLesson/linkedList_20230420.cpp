#include "linkedList_20230420.h"

C_LINKED_LIST_20230420::C_LINKED_LIST_20230420() :
	m_cBeginDummy{},
	m_cEndDummy{},
	m_pBegin{},
	m_pEnd{}
{

	m_pBegin = &m_cBeginDummy;
	m_pEnd = &m_cEndDummy;
	
	m_pBegin->m_pNextNode = m_pEnd;
	m_pEnd->m_pPreviousNode = m_pBegin;
	
}

C_NODE_20230420* C_LINKED_LIST_20230420::createNode(int nData)
{
	C_NODE_20230420* pNewNode = new C_NODE_20230420{};
	pNewNode->m_nData = nData;
	pNewNode->m_pNextNode = nullptr;
	pNewNode->m_pPreviousNode = nullptr;

	return pNewNode;
}

void C_LINKED_LIST_20230420::linkNode(C_NODE_20230420* pPrev, C_NODE_20230420* pNext)
{
	pPrev->m_pNextNode = pNext;
	pNext->m_pPreviousNode = pPrev;
}

C_NODE_20230420* C_LINKED_LIST_20230420::getBegin()
{
	return m_pBegin->m_pNextNode;
}

C_NODE_20230420* C_LINKED_LIST_20230420::getEnd()
{
	return m_pEnd;
}

void C_LINKED_LIST_20230420::pushBack(int nData)
{
	C_NODE_20230420* newNode = createNode(nData);
	
	linkNode(m_pEnd->m_pPreviousNode, newNode);
	linkNode(newNode, m_pEnd);
}

void C_LINKED_LIST_20230420::pushFront(int nData)
{
	C_NODE_20230420* newNode = createNode(nData);

	linkNode(m_pBegin, newNode);
	linkNode(newNode, m_pBegin->m_pNextNode);
	
}
