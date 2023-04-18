#include "20230418_list.h"

#include<stdio.h>
C_20230418_LIST::S_NODE* C_20230418_LIST::createNode(int nData, S_NODE* pNext)
{
	S_NODE* pTemp = new S_NODE{};
	pTemp->m_nData = nData;
	pTemp->pNext = pNext;

	return pTemp;
}
void C_20230418_LIST::add(int nData)
{
	S_NODE* pNewNode = createNode(nData, nullptr);

	if (!m_pBegin)
		m_pBegin = pNewNode;
	else
		m_pEnd->pNext = pNewNode;

	m_pEnd = pNewNode;
}


void C_20230418_LIST::print(void)
{
	C_20230418_LIST::S_NODE* pTemp = m_pBegin;
	while (pTemp)
	{
		printf("%d ", pTemp->m_nData);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

void C_20230418_LIST::remove(int nData)
{
	S_NODE* pPrevious = nullptr;
	S_NODE* pCurrent = m_pBegin;

	while (pCurrent)
	{
		S_NODE* pNext = pCurrent->pNext;

		if (pCurrent->m_nData == nData)
		{
			S_NODE* pDeleteTarget = pCurrent;

			if (pDeleteTarget == m_pBegin)
				m_pBegin = pNext;
			else
				pPrevious->pNext = pNext;

			if (pDeleteTarget == m_pEnd)
				m_pEnd = pPrevious;

			delete pDeleteTarget;
			pDeleteTarget = nullptr;
		}
		else
			pPrevious = pCurrent;

		pCurrent = pNext;
	}
}
