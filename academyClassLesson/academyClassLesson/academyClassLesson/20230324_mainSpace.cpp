#include<iostream>

#include"20230324_operator.h"
#include"20230324_class.h"
//https://learn.microsoft.com/ko-kr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
// ��� �� ���� �ٽ� ����

void func_C20230324_DATA_01(C20230324_DATA_01 c);
void func_C20230324_C_DATA_02(C20230324_C_DATA_02 c);

void mainSpace_20230324_04(void)
{
	C20230324_C_DATA_02 cData{};

	// �̰� ��������.
	cData++;
	printf("%d\n", cData.getData());

	// �̰� ��������.
	printf("%d\n", (++cData).getData());
	printf("%d\n", cData.getData());

	cData++;
	printf("%d\n", cData.getData());

}

int mainSpace_20230324_01(void)
{
	C20230324_DATA_01 c{};
	func_C20230324_DATA_01(c);
	func_C20230324_DATA_01(C20230324_DATA_01());

	return 0;
}

int mainSpace_20230324_02(void)
{
	C20230324_C_DATA cData{};

	cData.setData(3, 10);
	printf("%d\n", cData[3]);
	return 0;
}

void mainSpace_20230324_03(void)
{
	int nData{};
	C20230324_C_DATA_02 cData{};

	//�̰� �ȴ�
	++++++++++nData;
	// �̰� �ȵȴ� 
	// nData++++++++;
	printf("%d\n", nData);

	++++++++++++++cData;
	func_C20230324_C_DATA_02(++cData);
	printf("%d\n", cData.getData());

}




void func_C20230324_DATA_01(C20230324_DATA_01 c)
{
}
void func_C20230324_C_DATA_02(C20230324_C_DATA_02 c)
{
	printf("%d\n", c.getData());
}
