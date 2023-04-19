#include "linkedList_20230419.h"

C_LIST_20230419::C_LIST_20230419() :
	m_pBegin{},
	m_ppEnd{}
{
	m_ppEnd = &m_pBegin;
}

C_LIST_20230419::S_NODE* C_LIST_20230419::createNode(int nData)
{
	S_NODE* S_Node = new S_NODE{};
	S_Node->nData = nData;
	S_Node->pNext = nullptr;
	return S_Node;
}

void C_LIST_20230419::add(int nData)
{
	*m_ppEnd = createNode(nData);
	m_ppEnd = &(*m_ppEnd)->pNext;
}

void C_LIST_20230419::print()
{
	S_NODE* pNode = m_pBegin;
	
	while (pNode)
	{
		printf("%d ", pNode->nData);
		pNode = pNode->pNext;
	}

	printf("\n");
}

void C_LIST_20230419::remove(int nData)
{
	S_NODE** ppNode = &m_pBegin;

	while (*ppNode)
	{
		if ((*ppNode)->nData == nData)
		{
			S_NODE* pDeleteNode = *ppNode;
			*ppNode = pDeleteNode->pNext;

			delete pDeleteNode;
		}
		else
			ppNode = &(*ppNode)->pNext;
	}

	m_ppEnd = ppNode;
}
