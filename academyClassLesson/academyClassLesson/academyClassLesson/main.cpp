#include<iostream>
#include"add_230313.h"

int main(void)
{
	C_ADD cAdd{};
	cAdd.setData(10, 20);
	
	printf("sum of 10 and 20 is %d", cAdd.getSum());
}