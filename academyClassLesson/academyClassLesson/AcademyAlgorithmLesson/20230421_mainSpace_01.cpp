#include<iostream>

#include"20230421_linkedList_List.h"

void printList(C_node_2023_04_21* pListBegin, C_node_2023_04_21* pListEnd);
void remove(C_linked_list_2023_04_21* pList, int nData);

int mainSpace01_20230421(void)
{
	C_linked_list_2023_04_21 c_list{};
	c_list.pushBack(1);
	c_list.pushBack(2);
	c_list.pushBack(3);
	c_list.pushBack(3);
	c_list.pushBack(3);
	c_list.pushBack(3);
	c_list.pushBack(4);
	c_list.pushBack(3);
	c_list.pushBack(4);
	c_list.pushBack(3);
	c_list.pushBack(4);
	c_list.pushBack(5);

	printList(c_list.getBegin(), c_list.getEnd());
	remove(&c_list, 3);
	printList(c_list.getBegin(), c_list.getEnd());

	return 0;
}

void printList(C_node_2023_04_21* pListBegin, C_node_2023_04_21* pListEnd)
{
	C_node_2023_04_21* pCurrent = pListBegin;
	while (pCurrent != pListEnd)
	{
		std::cout << pCurrent->getData() << " ";
		pCurrent = pCurrent->getNextNode();
	}
	std::cout << std::endl;
}

void remove(C_linked_list_2023_04_21* pList, int nData)
{
	C_node_2023_04_21* pCurrent = pList->getBegin();
	while (pCurrent != pList->getEnd())
	{
		C_node_2023_04_21* pNext = pCurrent->getNextNode();
		if (pCurrent->getData() == nData)
		{
			pList->deleteNode(pCurrent);
		}
		pCurrent = pNext;
	}
}

