#include<iostream>
#include"Data_230313.h"
#include"add_230313.h"
int mainSpace1(void)
{
	C_DATA_230313 cData{};

	cData.setData(100);
	printf("%d", cData.getData());
}

int mainSpace2(void)
{
	C_ADD cAdd{};
	cAdd.setData(10, 20);

	printf("sum of 10 and 20 is %d", cAdd.getSum());

}