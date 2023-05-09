#include<iostream>
#include"20230509_BST_DoublePointer.h"
int main(void)
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
	
	cBST.print();
	cBST.erase(2);
	cBST.print();

	return 0;
}
