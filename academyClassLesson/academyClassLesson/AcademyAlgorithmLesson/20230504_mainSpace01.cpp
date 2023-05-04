#include<iostream>

#include "20230504_BinarySearchTree.h"

int mainSpace01_20230504(void)
{
	C_BST_20230504 cBST{};

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
	cBST.erase(7);

	cBST.print();

	//______________//

	C_BST_20230504 cBST2{};

	//5
	cBST2.add(5);
	cBST2.print();
	cBST2.erase(5);
	cBST2.print();
	cBST2.add(2);
	cBST2.print();

	return 0;
}
