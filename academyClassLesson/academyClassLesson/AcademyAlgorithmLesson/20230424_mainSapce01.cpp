#include<iostream>

#include"20230424_heap.h"
int mainSpace01_20230424(void)
{

	C20230424_HEAP cHeap{};

	cHeap.init(10);

	//8 4 3 10 15 13
	cHeap.add(8);
	cHeap.add(10);
	cHeap.add(15);
	cHeap.add(4);
	cHeap.add(3);
	cHeap.add(13);

	cHeap.print();

	cHeap.release();


	C20230424_HEAP cHeap2{};

	cHeap2.init(10);

	//8 4 3 10 15 13

	cHeap2.add_recursion(8);
	cHeap2.add_recursion(10);
	cHeap2.add_recursion(15);
	cHeap2.add_recursion(4);
	cHeap2.add_recursion(3);
	cHeap2.add_recursion(13);

	cHeap2.print();

	cHeap2.release();

	return 0;
}
