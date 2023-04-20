#pragma once

#include"20230420Node.h"

class C_LINKED_LIST_20230420_1
{
	friend class C_NODE_20230320;
private:
	C_NODE20230420_1* m_beginNode;
	C_NODE20230420_1* m_endNode;
	C_NODE20230420_1 m_beginDummy;
	C_NODE20230420_1 m_endDummy;
public:
	C_LINKED_LIST_20230420_1();
	~C_LINKED_LIST_20230420_1() = default;

	//delete copy assignment and operator =
	C_LINKED_LIST_20230420_1(const C_LINKED_LIST_20230420_1& other) = delete;
	C_LINKED_LIST_20230420_1& operator=(const C_LINKED_LIST_20230420_1& other) = delete;

private:
	C_NODE20230420_1* createNode(int nData);
	
public:
	C_NODE20230420_1* getBegin(void);
	C_NODE20230420_1* getEnd(void);

	void pushBack(int nData);
	void pushFront(int nData);
};
	

