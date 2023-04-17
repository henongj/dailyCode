#include "20230417_list.h"
#include<stdio.h>
C_LIST::S_NODE* C_LIST::createNode(int nData, S_NODE* pNext)
{
	S_NODE* pTemp = new S_NODE{};
	pTemp->m_nData = nData;
	pTemp->pNext = pNext;

	return pTemp;
}
void C_LIST::add(int nData)
{
	S_NODE* pNewNode = createNode(nData, nullptr);

	if (!m_pBegin)
		m_pBegin = pNewNode;
	else
		m_pEnd->pNext = pNewNode;

	m_pEnd = pNewNode;
}


void C_LIST::print(void)
{
	C_LIST::S_NODE* pTemp = m_pBegin;
	while (pTemp)
	{
		printf("%d ", pTemp->m_nData);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

void C_LIST::remove(int nData)
{
	S_NODE* pPrevious = nullptr;
	S_NODE* pCurrent = m_pBegin;
	
	while (pCurrent)
	{
		// pCurrent->m_nData가 nData랑 같으면 죄다 삭제해야한다.
		/*
		while (pCurrent->m_nData == nData)
		{
			pCurrent = pCurrent->pNext;
			delete pPrevious->pNext;
			pPrevious->pNext = pCurrent;
		}
		
		// pCurrent->m_nData는 nData랑 다르니 앞으로 가야한다.
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
		*/
		if(pCurrent->m_nData == nData)
		{
			pCurrent = pCurrent->pNext;
			delete (pPrevious->pNext);
			pPrevious->pNext = pCurrent;
		}

		else
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}
	
}
