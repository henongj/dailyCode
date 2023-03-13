#include<iostream>
#include"Data_230313.h"

int mainSpace(void)
{
	C_DATA_230313 cData{};

	cData.setData(100);
	printf("%d", cData.getData());
}