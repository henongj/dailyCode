#pragma once
#include<iostream>

namespace academyLecture_2023_02_23
{

	int add(int, int);
	float add(float, float);

	// const int& �� ����� ���յƴ�
	// printf("%d \n", add(10, 20)); �̰� ����� �� ������ ���
	// �ֳĸ� ��ũ�� Ȯ���� ���� ��� ��ȣ�ϴϱ� ������ ����
	// �׷��� �̷��� ���� �ϰ� �� ���� ������ �� ���ٰ�
	int add(const int& nData1, const int& nData2);
	// �̷��� �ص� ������ ���ٰ�
	// �μ��� ������ ��ũ�� �� ��� �Ͱ� �����ؾ� �ϴ��� ��ȣ�ؼ� ������ ���ٰ�
	int add(int nData1, int nData2, int nData3 = 10);
	// C��� Ư���� call by value���� call by reference���� ��ȣ�ϴ�
	// func(20)�� template ���� ����ϸ� ȣ��� ���ɼ� �մ� �Լ��� 4����

	void func(int nData);

	int mainTest(void)
	{
		//printf("%d \n", add(10, 20));
		printf("%f \n", add(10.5f, 20.0f));

		//�ּ� Ȯ���غ�
		func(0);
	}

	int add(int nData1, int nData2)
	{
		return nData1 + nData2;
	}

	float add(float nData1, float nData2)
	{
		return nData1 + nData2;
	}


	//�Լ� ����
	//��¼�� ��¼�� data�� ��¼��
	void func(int nData)
	{

	}
}