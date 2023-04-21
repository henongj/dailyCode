#include "20230421_linkedList_node.h"

C_node_2023_04_21::C_node_2023_04_21():
	m_nData{},
	m_pPrevNode{},
	m_pNextNode{}
{

}

int C_node_2023_04_21::getData()
{
	return m_nData;
}

C_node_2023_04_21* C_node_2023_04_21::getNextNode()
{
	return m_pNextNode;
}
