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
		int nData1{}; // 생성
		int nData2 = 10; // 생성하면서 동시에 초기화 

		C_DATA_23_03_10 cData1{}; // 생성

		printf("get data 호출,\n m_nData : %d ", cData1.getData());
	}

	
	// 기본으로 설정된 생성자이고, 이때 m_nData가 초기화되지 않는다
	C_DATA_23_03_10::C_DATA_23_03_10() : m_nData{}
	{
		printf("constructor 호출\n");
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
		// cData1 에서 ()를 붙이면 함수 선언인줄 안다? 함수 프로토타입으로 읽어서 문법체계가 꼬여
// 그래서 아무것도 안 붙이고 cData1; 로 세미클론만 붙이게 됐는데 이게 C11에서 해결하기 위해 등장한게 {}인거지
		C_DATA2 cData1;

		// 그런데 얘들은 함수 선언 문법이랑 같아
		C_DATA2 cData2(10);
		// 그런데 선언과 동시에 = 은 생성자를 호출하는거야 그래서 이렇게도 가능해
		C_DATA2 cData5 = 99; // 이런식으로 대입하는걸 "묵시적 변환"인지 뭔지라 그래
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
		printf("기본 생성자\n");
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