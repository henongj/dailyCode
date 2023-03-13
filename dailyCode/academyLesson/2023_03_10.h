#include<iostream>
namespace lecture_2023_03_10
{

	class C_DATA_23_03_10
	{
	private:
		int m_nData;
	public:
		C_DATA_23_03_10();
		void setData(int nData);
		int getData();
	};

	
	void mainSpace1(void)
	{
		int nData1{}; // ����
		int nData2 = 10; // �����ϸ鼭 ���ÿ� �ʱ�ȭ 

		C_DATA_23_03_10 cData1{}; // ����

		printf("get data ȣ��,\n m_nData : %d ", cData1.getData());
	}

	
	// �⺻���� ������ �������̰�, �̶� m_nData�� �ʱ�ȭ���� �ʴ´�
	C_DATA_23_03_10::C_DATA_23_03_10() : m_nData{}
	{
		printf("constructor ȣ��\n");
	}

	void C_DATA_23_03_10::setData(int nData)
	{
		m_nData = nData;
	}

	int C_DATA_23_03_10::getData()
	{
		return m_nData;
	}



	class C_DATA2
	{
	public:
		C_DATA2();
		C_DATA2(int nData);
		// explicit C_DATA2(int nData);
		C_DATA2(int nData1, int nData2);
		C_DATA2(int nData1, int nData2, int nData3);
	};
	
	void mainSpace2(void)
	{
		// cData1 ���� ()�� ���̸� �Լ� �������� �ȴ�? �Լ� ������Ÿ������ �о ����ü�谡 ����
// �׷��� �ƹ��͵� �� ���̰� cData1; �� ����Ŭ�и� ���̰� �ƴµ� �̰� C11���� �ذ��ϱ� ���� �����Ѱ� {}�ΰ���
		C_DATA2 cData1;

		// �׷��� ����� �Լ� ���� �����̶� ����
		C_DATA2 cData2(10);
		// �׷��� ����� ���ÿ� = �� �����ڸ� ȣ���ϴ°ž� �׷��� �̷��Ե� ������
		C_DATA2 cData5 = 99; // �̷������� �����ϴ°� "������ ��ȯ"���� ������ �׷�
		C_DATA2 cData6{ 123 };
		C_DATA2 cData3(10, 20);
		C_DATA2 cData4(10, 20, 30);

	}

	C_DATA2::C_DATA2(int nData)
	{
		printf("C_DATA 1 : %d \n", nData);
	}

	C_DATA2::C_DATA2(int nData1, int nData2)
	{
		printf("C_DATA 2 : %d %d \n", nData1, nData2);

	}

	C_DATA2::C_DATA2(int nData1, int nData2, int nData3)
	{
		printf("C_DATA 2 : %d %d %d\n", nData1, nData2, nData3);
	}

	C_DATA2::C_DATA2()
	{
		printf("�⺻ ������\n");
	}



	class C_NOW
	{
	private:
		int m_nData;

	public:
		void init(int nData);
		void printData();
		int getData();
	};

	int mainSpace4(void)
	{
		C_NOW cNow{};

		cNow.init(15);
		cNow.printData();

		printf("%d\n", cNow.getData());

	}

	void C_NOW::init(int nData) {
		m_nData = nData;
	}

	void C_NOW::printData()
	{
		printf("%d\n", m_nData);
	}

	int C_NOW::getData()
	{
		return m_nData;
	}

}