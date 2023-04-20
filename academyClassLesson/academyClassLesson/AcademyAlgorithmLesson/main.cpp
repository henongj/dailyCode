#include<iostream>

#include"linkedList_20230420.h"

int main(void)
{
	C_LINKED_LIST_20230420 cLinkedList{};

	C_NODE_20230420* pBegin = cLinkedList.getBegin();
	
	cLinkedList.pushBack(1);
	cLinkedList.pushBack(2);
	cLinkedList.pushBack(3);

	while(pBegin != cLinkedList.getEnd())
	{
		std::cout << pBegin->getData() << std::endl;
		pBegin = pBegin->getNextNode();
	}

	
	return 0;
}
