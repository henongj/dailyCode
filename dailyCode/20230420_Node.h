#pragma once

#include"20230420_LinkedList.h"

class C20230420_Node
{
	friend class C20230420_LinkedList;
private:
	int m_nData;
	C20230420_Node* m_pNextNode;
	C20230420_Node* m_pPreviousNode;

public:
	C20230420_Node();
	~C20230420_Node() = default;
	
	int getData(void);
	C20230420_Node* getNextNode(void);
};
