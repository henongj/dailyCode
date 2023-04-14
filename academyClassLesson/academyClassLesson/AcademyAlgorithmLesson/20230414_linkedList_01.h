#pragma once

#include<iostream>

struct S_20230414_NODE
{
	int nData;
	S_20230414_NODE* pNext;
};

void add(S_20230414_NODE*& pBegin, int nData);
void printNode(S_20230414_NODE* pNode);


int mainSpace01_20230414(void)
{
	S_20230414_NODE* pBegin{};

	pBegin = new S_20230414_NODE{ 1, nullptr };
	pBegin->pNext = new S_20230414_NODE{ 2, nullptr };
	pBegin->pNext->pNext = new S_20230414_NODE{ 3, nullptr };
	pBegin->pNext->pNext->pNext = new S_20230414_NODE{ 4, nullptr };

	return 0;
}

int mainSpace02_20230414(void)
{
	S_20230414_NODE* pBegin{};

	pBegin = new S_20230414_NODE{ 1, nullptr };
	pBegin->pNext = new S_20230414_NODE{ 2, nullptr };
	pBegin->pNext->pNext = new S_20230414_NODE{ 3, nullptr };
	pBegin->pNext->pNext->pNext = new S_20230414_NODE{ 4, nullptr };

	printNode(pBegin);

	return 0;
}

void add(S_20230414_NODE*& pBegin, int nData)
{
	if (!pBegin)
	{
		pBegin = new S_20230414_NODE{ nData, nullptr };
		return;
	}

	S_20230414_NODE* pTemp = pBegin;
	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;
	}

	pTemp->pNext = new S_20230414_NODE{ nData, nullptr };
}

void printNode(S_20230414_NODE* pNode)
{
	while (pNode)
	{
		printf("%d ", pNode->nData);
		pNode = pNode->pNext;
	}
}

