#include "20230420_LinkedList.h"

C20230420_LinkedList::C20230420_LinkedList() :
	m_pBeginNode{},
	m_pEndNode{},
	m_cBeginDummy{},
	m_cEndDummy{}
{
	m_pBeginNode = &m_cBeginDummy;
	m_pEndNode = &m_cEndDummy;

	m_pBeginNode->m_pNextNode = m_pEndNode;
	m_pEndNode->m_pPreviousNode = m_pBeginNode;
}
