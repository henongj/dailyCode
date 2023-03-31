#include<iostream>


#include"C20230331_PureVirtualFunctionTest.h"

int mainSpace01_C20230331(void)
{
	C202303301_virtual* pTest{};
	pTest = new C202303301_test();

	pTest->printTest();

	delete pTest;

	return 0;
}

int mainSpace02_C20230331(void)
{
	C202303301_virtual* pTest{};
	pTest = new C202303301_test();

	pTest->printTest();

	C202303301_virtual& pTest2 = *pTest;
	pTest2.printTest();

	delete pTest;

	return 0;
}
