#pragma once

#include"20230420_Node.h"

class C20230420_LinkedList
{
	
private:
	C20230420_Node* m_pBeginNode;
	C20230420_Node* m_pEndNode;
	C20230420_Node m_cBeginDummy;
	C20230420_Node m_cEndDummy;

public:
	C20230420_LinkedList();
	~C20230420_LinkedList() = default;
	
	//delete copy assignment and operator =

private:
	C20230420_Node* createNode(int nData);

public:

	C20230420_Node* getBegin();
	C20230420_Node* getEnd();

	void pushBack(int nData);
	void pushFront(int nData);
	
};