#pragma once

#include"20230421_linkedList_node.h"

class C_linked_list_2023_04_21
{
private:
	C_node_2023_04_21* m_pBegin;
	C_node_2023_04_21* m_pEnd;
	C_node_2023_04_21 m_cBeginDummy;
	C_node_2023_04_21 m_cEndDummy;

public:
	C_linked_list_2023_04_21();
	~C_linked_list_2023_04_21() = default;

	//delete copy assignment and operator =
	C_linked_list_2023_04_21(const C_linked_list_2023_04_21& other) = delete;
	C_linked_list_2023_04_21& operator=(const C_linked_list_2023_04_21& other) = delete;

private:
	C_node_2023_04_21* createNode(int nData);
	void linkNode(C_node_2023_04_21* pPrev, C_node_2023_04_21* pNext);
	void insertNode(C_node_2023_04_21* pPrev, C_node_2023_04_21* pNewNode, C_node_2023_04_21* pNext);
	
public:

	C_node_2023_04_21* getBegin();
	C_node_2023_04_21* getEnd();

	void pushBack(int nData);
	void pushFront(int nData);

	void deleteNode(C_node_2023_04_21* pNode);
	void removeNode(C_node_2023_04_21* pBegin, C_node_2023_04_21* pEnd, int nData);
	void printList();
};

	