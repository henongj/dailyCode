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

	// �ٶ������� �ʴ�
	for (int i = 0; i < 10; i++)
	{
		printf("�� : %d", cAdd.getSum());
	}

	// ��� ��Ȱȭ, �̰��� �ٶ����ϴ�
	cAdd.update();
	int nSum = cAdd.getSum();

	for (int i = 0; i < 10; i++)
	{
		printf("�� : %d", nSum);
	}
}