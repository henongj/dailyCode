#include<iostream>
namespace academyLecture_2023_03_06
{

	void func();
	class C_Test
	{
	private:
		int m_nData1;
		int m_nData2;
		int m_nData3;
		int m_nData4;
	public:
		void dsetData(int nData);
		void printData(void);
	};
	namespace N_MATH
	{
		int add(int nData1, int nData2);
		int multiple(int nData1, int nData2);
		void func();
	}
	void mainSpace2(void)
	{
		C_Test cTest1{};
		C_Test cTest2{};

		cTest1.dsetData(10);
		cTest2.dsetData(20);

		cTest1.printData();
		cTest2.printData();
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

	void C_Test::dsetData(int nData1)
	{
		C_Test::m_nData1 = nData1;
		printf("�׽�Ʈ �Դϴ�. %d\n", nData1);
	}

	void C_Test::printData(void)
	{
		printf("%d %d %d %d\n", m_nData1, m_nData2, m_nData3, m_nData4);
	}

}