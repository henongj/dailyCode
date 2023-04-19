#pragma once

#include<stdio.h>

class C_LIST_20230419
{
private:
	struct S_NODE
	{
		int nData;
		S_NODE* pNext;
	};

private:
	S_NODE* m_pBegin;
	S_NODE** m_ppEnd;
	
public:
	C_LIST_20230419();
	~C_LIST_20230419() = default;

	C_LIST_20230419::S_NODE* createNode(int nData);
	void add(int nData);
	void print();
	void remove(int nData);
};
