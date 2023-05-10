#include<iostream>
#include"20230509_BST_DoublePointer.h"
int mainSpace01_20230510(void)
{
	C20230509_BinarySearchTree cBST{};
	//4 1 9 8 3 5 2 6 7
	cBST.add(4);
	cBST.add(1);
	cBST.add(9);
	cBST.add(8);
	cBST.add(3);
	cBST.add(5);
	cBST.add(2);
	cBST.add(6);
	cBST.add(7);
	cBST.add(10);

	if (!cBST.add(10))
		std::cout << "10 is already exist" << std::endl;

	cBST.print();

	if (cBST.find(4))
		std::cout << "4 is exist" << std::endl;

	cBST.erase(4);

	if (!cBST.find(4))
		std::cout << "4 isn;t exist" << std::endl;

	cBST.print();



	return 0;
}
