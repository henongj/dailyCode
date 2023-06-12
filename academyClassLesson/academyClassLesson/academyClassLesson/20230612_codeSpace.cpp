#include<iostream>
#include<set>
#include<map>

#include"20230607_librarySystem.h"

int mainSpace01_20230612(void)
{
	C20230607_librarySystem librarySystem{};
	librarySystem.init();

	librarySystem.rentBook(34, 1);

	librarySystem.printAllBorrowedBook();

	return 0;
}