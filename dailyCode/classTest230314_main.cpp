#include<stdio.h>

#include"classTest230314_1.h"

void mainSpace1(void)
{
	classTest230314_1 cClassTest230314_1{};
	
	cClassTest230314_1.setTestData(1);
	
	printf("cClassTest230314_1.getTestData()->getTestData() = %d", cClassTest230314_1.getTestData()->getTestData());
}

void mainSpace2(void)
{

	classTest230314_1 cClassTest230314_1{};


	cClassTest230314_1.setTestData(25);

	printf("setTestData : %d\n", cClassTest230314_1.getTestData()->getTestData());
	
	cClassTest230314_1.getTestData()->getTestData();

	printf("cClassTest230314_1.getTestData()->getTestData() = %d\n", cClassTest230314_1.getTestData()->getTestData());

	cClassTest230314_1.getTestData()->setTestData(55);

	printf("getTestData()->setTestData() = %d\n", cClassTest230314_1.getTestData()->getTestData());

}