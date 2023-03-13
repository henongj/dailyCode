#include<iostream>
#include"Data_230313.h"
#include"add_230313.h"
void mainSpace1(void)
{
	C_DATA_230313 cData{};

	cData.setData(100);
	printf("%d", cData.getData());
}

void mainSpace2(void)
{
	C_ADD cAdd{};
	cAdd.setData(10, 20);

	printf("sum of 10 and 20 is %d", cAdd.getSum());

}

void mainSpace3(void)
{
	C_ADD cAdd{};
	cAdd.setData(10, 20);

	// 바람직하지 않다
	for (int i = 0; i < 10; i++)
	{
		printf("합 : %d", cAdd.getSum());
	}

	// 백업 생활화, 이것이 바람직하다
	cAdd.update();
	int nSum = cAdd.getSum();

	for (int i = 0; i < 10; i++)
	{
		printf("합 : %d", nSum);
	}
}