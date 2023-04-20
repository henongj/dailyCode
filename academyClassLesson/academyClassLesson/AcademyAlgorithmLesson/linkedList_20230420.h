#pragma once

#include"node_20230420.h"

class C_LINKED_LIST_20230420
{
	friend class C_NODE_20230420;
private:
	C_NODE_20230420* m_pBegin;
	C_NODE_20230420* m_pEnd;
	C_NODE_20230420 m_cBeginDummy;
	C_NODE_20230420 m_cEndDummy;
	
public:
	C_LINKED_LIST_20230420();
	~C_LINKED_LIST_20230420() = default;

	//delete copy assignment and operator =
	C_LINKED_LIST_20230420(const C_LINKED_LIST_20230420& other) = delete;
	C_LINKED_LIST_20230420& operator=(const C_LINKED_LIST_20230420& other) = delete;

private:
	C_NODE_20230420* createNode(int nData);
	void linkNode(C_NODE_20230420* pPrev, C_NODE_20230420* pNext);
public:
	
	C_NODE_20230420* getBegin();
	C_NODE_20230420* getEnd();

	void pushBack(int nData);
	void pushFront(int nData);
};