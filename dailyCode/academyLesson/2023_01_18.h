#include<iostream>
namespace lecture_2023_01_18
{
	void fGetAreaOfRectangle(void)
	{
		int nWidth{};
		int nHeight{};
		int nArea{};

		std::cin >> nWidth;
		std::cin >> nHeight;

		nArea = nWidth * nHeight;

		std::cout << "면적 : " << nArea << std::endl;

	}

	void getNumAndPrint(void)
	{
		int nData{};

		nData = 100;

		scanf_s("%d", &nData);

		int* nDataAdress = &nData;
		printf_s("출력 : %d\n", nData);
		printf_s("주소 : %p\n", nDataAdress);

	}

	void getQuotient(void)
	{
		int nData1{};
		int nData2{};
		int nQuotient{};

		scanf_s("%d", &nData1);
		scanf_s("%d", &nData2);

		nQuotient = nData1 / nData2;

		printf_s("출력 : %d\n", nQuotient);
	}


	void castPractice(void)
	{
		int nData1{};
		int nData2{};
		float fData{};

		fData = 0.0f;
		nData1 = 100;
		nData2 = 7;

		fData = 10.0f / 7.0f;
		printf("fData = %f\n", fData);

		// fData = (float)(nData1 / nData2) 하지마라 뒤진다
		fData = (float)nData1 / (float)nData2;
		printf("fData = %f\n", fData);

	}
	
}