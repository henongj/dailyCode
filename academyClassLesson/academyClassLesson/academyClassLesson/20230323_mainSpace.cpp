#include<iostream>

#include<iostream>

#include"2023_03_23_classOperator.h"
void mainSpace_20230323_01(void)
{
	C20230323ClassOperator cData1{};
	C20230323ClassOperator cData2{};

	//�̰� �� �������?
	cData1.setData(10);
	//�̷��� �Ǵµ�? operator = �� �����ϸ� �̷� ��Ģ�� ��������
	cData1 = 200;

	//������ ���ʰ� ������ �ڷ����� �ٸ��ܰž�
	cData2 = cData1 + 12;

	cData2.printData();


}
