#include<iostream>
namespace academyLecture_2023_03_06
{

	void func();

	namespace N_MATH
	{
		int add(int nData1, int nData2);
		int multiple(int nData1, int nData2);
		void func();
	}
	void mainSpace(void)
	{
		printf("%d\n", N_MATH::add(20, 30));
		{
			using namespace N_MATH;
			printf("%d\n", add(10, 20));
		}

		func();
		N_MATH::func();

		printf("\n���� �����̽��� ���̴� ��Ȳ\n���� �Լ��̸� �ٲ۴� \n");
		N_MATH::multiple(33, 44);

		{
			using namespace N_MATH;
			// ���ӽ����̽��� ������ ��ȣ�ϹǷ� ����
			// func();
		}

	}

	int N_MATH::add(int nData1, int nData2)
	{

		return nData1 + nData2;
	}
	int N_MATH::multiple(int nData1, int nData2)
	{
		func();
		::func();
		return nData1 * nData2;
	}

	void N_MATH::func()
	{
		printf("N_MATH �Լ�\n");
	}

	void func()
	{
		//�ܺο��� �����Դٰ� ����
		printf("���� �Լ�\n");
	}

}