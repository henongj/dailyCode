#include "20230420_Node.h"

C20230420_Node::C20230420_Node(void):
	m_nData{},
	m_pNextNode{},
	m_pPreviousNode{}
{
}

int C20230420_Node::getData(void)
{
	return m_nData;
}

C20230420_Node* C20230420_Node::getNextNode(void)
{
	return m_pNextNode;
}
