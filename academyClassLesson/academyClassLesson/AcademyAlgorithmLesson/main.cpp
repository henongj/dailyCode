#include<iostream>

#include "20230503_BinarySearchTree.h"

int main(void)
{
	C_BST_20230503 cBST{};

	//5 1 3 6 8 2 9 7 4
	cBST.add(5);
	cBST.add(1);
	cBST.add(3);
	cBST.add(6);
	cBST.add(8);
	cBST.add(2);
	cBST.add(9);
	cBST.add(7);
	
	if (!cBST.add(3))
		printf("fail\n");
	
	cBST.print();
	
	return 0;
}
