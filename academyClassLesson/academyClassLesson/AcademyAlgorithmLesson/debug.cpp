
#include "debug.h"

int add_20230410(int nData1, int nData2);

int mainSpace02_20230410(void)
{
	int* p1{};
	int* p2{};
	int* p3{};

	p1 = new int{};
	p2 = p3 = p1;

	*p1 = 100;

	*p3 = 10;
	return 0;
}

int mainSpace01_20230410(void)
{
	int nData1{};
	int nData2{};
	int nTotal{};

	nData1 = 100;
	nData2 = 200;


	nTotal = add_20230410(nData1, nData2);

	nTotal++;

	printf("%d\n", nTotal);

	return 0;
}

int add_20230410(int nData1, int nData2)
{

	return nData1 + nData2;
}
