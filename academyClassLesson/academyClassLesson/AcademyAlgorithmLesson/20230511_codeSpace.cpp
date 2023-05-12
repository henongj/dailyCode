#include<iostream>
#include"20230511_dataStatic.h"


void testStatic_20230511(void);

int mainSapce01_20230511(void)
{
	testStatic_20230511();
	testStatic_20230511();
	testStatic_20230511();


	return 0;
}

void mainSapce02_20230511(void)
{
	C20230511_DATA data1{};
	C20230511_DATA data2{};

	data1.setDataClass(10);
	std::cout << data1.getDataClass() << std::endl;
	std::cout << data2.getDataClass() << std::endl;
}

void testStatic_20230511(void)
{
	static int nData{};
	nData += 10;
	printf("%d\n", nData);
}
